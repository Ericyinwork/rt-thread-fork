# stm32h750-artpi移植lvgl

## 一、使用官方库点亮lcd

使用menuconfig进入env工具进行配置。

步骤一：

![image-20221227142106951](stm32h750-artpi%E7%A7%BB%E6%A4%8Dlvgl.assets/image-20221227142106951.png)

步骤二：

![image-20221227142239827](stm32h750-artpi%E7%A7%BB%E6%A4%8Dlvgl.assets/image-20221227142239827.png)

修改内存管理。否则会报错如下：

![image-20221227142331817](stm32h750-artpi%E7%A7%BB%E6%A4%8Dlvgl.assets/image-20221227142331817.png)

如果还是报错需要检查drv_spi.c修改

```c
spi_handle->Init.FifoThreshold   = SPI_FIFO_THRESHOLD_08DATA;
改为
spi_handle->Init.FifoThreshold   = SPI_FIFO_THRESHOLD_01DATA;
```

下载程序进入msh> ili9488_test 				屏幕被点亮！

![5f5092cf45fb4cf33a6be906b4ee2a8](stm32h750-artpi%E7%A7%BB%E6%A4%8Dlvgl.assets/5f5092cf45fb4cf33a6be906b4ee2a8.jpg)



## 与原仓库同步更新代码

[fork别人的项目保持与源项目同步更新的两种方式_fork的代码怎么保持最新_nash程序猴的博客-CSDN博客](https://blog.csdn.net/qq_43060570/article/details/130991121?spm=1001.2101.3001.6661.1&utm_medium=distribute.pc_relevant_t0.none-task-blog-2~default~CTRLIST~Rate-1-130991121-blog-103227170.235^v38^pc_relevant_anti_vip_base&depth_1-utm_source=distribute.pc_relevant_t0.none-task-blog-2~default~CTRLIST~Rate-1-130991121-blog-103227170.235^v38^pc_relevant_anti_vip_base)

```bash
git remote -v
origin  https://github.com/Ericyinwork/sdk-bsp-stm32h750-realthread-artpi.git (fetch)
origin  https://github.com/Ericyinwork/sdk-bsp-stm32h750-realthread-artpi.git (push)

git remote add upstream https://github.com/RT-Thread-Studio/sdk-bsp-stm32h750-realthread-artpi.git

git remote -v
origin  https://github.com/Ericyinwork/sdk-bsp-stm32h750-realthread-artpi.git (fetch)
origin  https://github.com/Ericyinwork/sdk-bsp-stm32h750-realthread-artpi.git (push)
upstream        https://github.com/RT-Thread-Studio/sdk-bsp-stm32h750-realthread-artpi.git (fetch)
upstream        https://github.com/RT-Thread-Studio/sdk-bsp-stm32h750-realthread-artpi.git (push)

从上游仓库 fetch 分支和提交点，传送到本地，并会被存储在一个本地分支 upstream/master
git fetch upstream			拉取远程分支

git merge upstream/master   //合并远程和本地分支
git push origin master		//将合并后的分支推送至git仓库

git config --global http.sslVerify "false" //重置ssl验证
 
ssh -T git@github.com      //测试与github是否连接成功

--hard 参数撤销工作区中所有未提交的修改内容，将暂存区与工作区都回到上一次版本，并删除之前的所有信息提交：
git reset --hard HEAD
实例：
$ git reset --hard HEAD~3  # 回退上上上一个版本  
$ git reset –hard bae128  # 回退到某个版本回退点之前的所有信息。 
$ git reset --hard origin/master    # 将本地的状态回退到和远程的一样 

```

## 如何把别人仓库作为sub子仓库



## MircoLIB为什么不使用

[STM32程序不运行与MicroLIB讲解_The Road of Engineer的博客-CSDN博客](https://blog.csdn.net/qq_36098477/article/details/117666808)