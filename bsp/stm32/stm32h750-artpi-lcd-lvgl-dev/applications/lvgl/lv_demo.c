/*
 * Copyright (c) 2006-2022, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author        Notes
 * 2022-01-28     Rudy Lo       The first version
 */
#include <rtthread.h>
#include <lvgl.h>
#include <lv_port_indev.h>
#define DBG_TAG    "LVGL.demo"
#define DBG_LVL    DBG_INFO
#include <rtdbg.h>

#include "lv_demo_rtt_music.h"

#ifndef LV_THREAD_STACK_SIZE
#define LV_THREAD_STACK_SIZE 4096
#endif

#ifndef LV_THREAD_PRIO
#define LV_THREAD_PRIO (RT_THREAD_PRIORITY_MAX * 2 / 3)
#endif

static void lvgl_thread(void *parameter)
{
  // extern void lv_demo_music1(void);
	//lv_demo_music();
	//lv_demo_music1();
	extern void gui_guider_setup(void);
	gui_guider_setup();

    /* handle the tasks of LVGL */
//	  lv_obj_t * obj = lv_obj_create(lv_scr_act());
//    lv_obj_set_width(obj, 200);
//    lv_obj_set_height(obj, 200);
//    lv_obj_set_size(obj,100, 200);

//    rt_kprintf("w:%d\n", lv_obj_get_width(obj));
//    rt_kprintf("h:%d\n", lv_obj_get_height(obj));

    while(1)
    {
        lv_task_handler();
        rt_thread_mdelay(10);
    }
}

void lv_user_gui_init(void)
{
	//add lv_user_gui code
		
}


static int lvgl_demo_init(void)
{
    rt_thread_t tid;

    tid = rt_thread_create("LVGL", lvgl_thread, RT_NULL, LV_THREAD_STACK_SIZE, LV_THREAD_PRIO, 0);
    if(tid == RT_NULL)
    {
        LOG_E("Fail to create 'LVGL' thread");
    }
    rt_thread_startup(tid);

    return 0;
}
INIT_APP_EXPORT(lvgl_demo_init);
