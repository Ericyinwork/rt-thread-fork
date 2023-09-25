/*
 * Copyright (c) 2006-2022, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2022-02-01     Rudy Lo      The first version
 */

#include <lvgl.h>
#include <lv_conf.h>
#include <rtthread.h>
#include "drv_spi_ili9488.h"

#define MY_DISP_HOR_RES     (LCD_W)
#define DISP_BUFFER_LINES   (LCD_H / 5)

/*A static or global variable to store the buffers*/
static lv_disp_draw_buf_t disp_buf;

/*Descriptor of a display driver*/
static lv_disp_drv_t disp_drv;

/*Static or global buffer(s). The second buffer is optional*/
static lv_color_t buf_1[MY_DISP_HOR_RES * DISP_BUFFER_LINES];
//static lv_color_t buf_2[MY_DISP_HOR_RES * DISP_BUFFER_LINES];


static rt_device_t device;
static struct rt_device_graphic_info info;
static struct rt_messagequeue *input_mq;
static int _lv_init = 0;
static lv_disp_drv_t disp_drv;
static lv_disp_draw_buf_t disp_buf;

static void color_to16_maybe(lv_color16_t *dst, lv_color_t *src)
{
#if (LV_COLOR_DEPTH == 16)
    dst->full = src->full;
#else
    dst->ch.blue = src->ch.blue;
    dst->ch.green = src->ch.green;
    dst->ch.red = src->ch.red;
#endif
}
static void lcd_fb_flush(lv_disp_drv_t *disp_drv, const lv_area_t *area, lv_color_t *color_p)
{
    int x1, x2, y1, y2;

    x1 = area->x1;
    x2 = area->x2;
    y1 = area->y1;
    y2 = area->y2;

    /*Return if the area is out the screen*/
    if (x2 < 0)
        return;
    if (y2 < 0)
        return;
    if (x1 > info.width - 1)
        return;
    if (y1 > info.height - 1)
        return;

    /*Truncate the area to the screen*/
    int32_t act_x1 = x1 < 0 ? 0 : x1;
    int32_t act_y1 = y1 < 0 ? 0 : y1;
    int32_t act_x2 = x2 > info.width - 1 ? info.width - 1 : x2;
    int32_t act_y2 = y2 > info.height - 1 ? info.height - 1 : y2;

    uint32_t x;
    uint32_t y;
    long int location = 0;

    /* 8 bit per pixel */
    if (info.bits_per_pixel == 8)
    {
        uint8_t *fbp8 = (uint8_t *)info.framebuffer;
        //TODO color convert maybe
        for (y = act_y1; y <= act_y2; y++)
        {
            for (x = act_x1; x <= act_x2; x++)
            {
                location = (x) + (y)*info.width;
                fbp8[location] = color_p->full;
                color_p++;
            }

            color_p += x2 - act_x2;
        }
    }

    /* 16 bit per pixel */
    else if (info.bits_per_pixel == 16)
    {
        lv_color16_t *fbp16 = (lv_color16_t *)info.framebuffer;

        for (y = act_y1; y <= act_y2; y++)
        {
            for (x = act_x1; x <= act_x2; x++)
            {
                location = (x) + (y)*info.width;
                color_to16_maybe(&fbp16[location], color_p);
                color_p++;
            }

            color_p += x2 - act_x2;
        }
    }
#ifndef BSP_USING_SPI_LCD_ILI9488
    /* 24 or 32 bit per pixel */
    else if (info.bits_per_pixel == 24 || info.bits_per_pixel == 32)
    {
        uint32_t *fbp32 = (uint32_t *)info.framebuffer;
        //TODO
        for (y = act_y1; y <= act_y2; y++)
        {
            for (x = act_x1; x <= act_x2; x++)
            {
                location = (x) + (y)*info.width;
                fbp32[location] = color_p->full;
                color_p++;
            }

            color_p += x2 - act_x2;
        }
    }
#else
    else if (info.bits_per_pixel == 24 || info.bits_per_pixel == 32)
    {
        uint8_t * lcd_buf = (uint8_t *)info.framebuffer;
        for (y = act_y1; y <= act_y2; y++)
        {
            for (x = act_x1; x <= act_x2; x++)
            {
                location = (x) + (y)*info.width;
                lcd_buf[3 * location] = color_p->ch.red;
                lcd_buf[3 * location + 1] = color_p->ch.green;
                lcd_buf[3 * location + 2] = color_p->ch.blue;
                color_p++;
            }
            color_p += x2 - act_x2;
        }
    }
#endif

    struct rt_device_rect_info rect_info;

    rect_info.x = x1;
    rect_info.y = y1;
    rect_info.width = x2 - x1 + 1;
    rect_info.height = y2 - y1 + 1;
    rt_device_control(device, RTGRAPHIC_CTRL_RECT_UPDATE, &rect_info);

    lv_disp_flush_ready(disp_drv);
}





/*Flush the content of the internal buffer the specific area on the display
 *You can use DMA or any hardware acceleration to do this operation in the background but
 *'lv_disp_flush_ready()' has to be called when finished.*/
static void disp_flush(lv_disp_drv_t * disp_drv, const lv_area_t * area, lv_color_t * color_p)
{
    /* color_p is a buffer pointer; the buffer is provided by LVGL */
    lcd_fill_array(area->x1, area->y1, area->x2, area->y2, color_p);


    /*IMPORTANT!!!
     *Inform the graphics library that you are ready with the flushing*/
    lv_disp_flush_ready(disp_drv);
}

void lv_port_disp_init(void)
{
    /*Initialize `disp_buf` with the buffer(s). With only one buffer use NULL instead buf_2 */
    lv_disp_draw_buf_init(&disp_buf, buf_1, RT_NULL, MY_DISP_HOR_RES * DISP_BUFFER_LINES);

    lv_disp_drv_init(&disp_drv); /*Basic initialization*/

    /*Set the resolution of the display*/
    disp_drv.hor_res = LCD_W;
    disp_drv.ver_res = LCD_H;

    /*Set a display buffer*/
    disp_drv.draw_buf = &disp_buf;

    /*Used to copy the buffer's content to the display*/
    disp_drv.flush_cb = disp_flush;

    /*Finally register the driver*/
    lv_disp_drv_register(&disp_drv);
}
