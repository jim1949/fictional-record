





# 武汉差动轮pv小车navigator管理方法

| 版本 | 负责人 | 日期       |
| ---- | ------ | ---------- |
| v1.0 | 焦健   | 2019.11.16 |
|      |        |            |
|      |        |            |



## 1.背景

目前武汉的差动轮项目正在试用绕障方案,但是由于现场空间有限,与韩信的绕障接口没有开发,导致在两辆车同时运行的时候,不便于展示该功能.这个文档主要是用于说明什么时候可以使用绕障,什么时候不用,已经切换方法.

## 2.分支功能说明

navigator目前可供使用的是两个,一个是之前测试了比较多次的只有停障的分支proj_JS_pv, 一个是目前还在开发的绕障分支replan_threaded_pv_test_1. 其中绕障分支replan_threaded_pv_test_1可以通过配置, 禁止绕障功能使用,但是目前还处于开发调试阶段,速度比较慢,最高速度为0.45m/s. 而停障分支proj_JS_pv的最高速度为0.9m/s.

## 3.切换分支说明

### 1)演示/调试绕障功能

 如果是演示或者调试单台车的绕障功能, 请把navigator切换到replan_threaded_pv_test_1, 执行如下指令:

```shell
$ roscd navigator_ros
$ git stash
$ git checkout replan_threaded_pv_test_1
$ cd param
$ vim navigator_ros_replan_options.yaml
```

修改replan_options/use_local_replan为true. 同时把 navigator_ros/param里面的navigator_ros_imr_replan.yaml里面的collision_checker/predictive_soft_stop_steps的步数调整到10.
修改完,重启一下navigator

```shell
$ cm
$ roslaunch navigator_ros imr_navigator_ros_replan.launch
```



### 2)平时使用

如果没有很急的演示要求, 请把navigator切换到replan_threaded_pv_test_1,执行如下指令:

```shell
$ roscd navigator_ros
$ git stash
$ git checkout replan_threaded_pv_test_1
$ cd param
$ vim navigator_ros_replan_options.yaml
```

修改replan_options/use_local_replan为false. 同时把 navigator_ros/param里面的navigator_ros_imr_replan.yaml里面的collision_checker/predictive_soft_stop_steps的步数调整到50.

因为现场的版本是一个新的框架,需要稳定性测试,证明它的稳定性.

```shell
$ cm
$ roslaunch navigator_ros imr_navigator_ros_replan.launch
```



### 3) 比较紧急的演示需求

如果有比较紧急的演示需求,可以把navigator切换到proj_JS_pv,执行如下指令:

```shell
$ roscd navigator_ros
$ git stash
$ git checkout proj_JS_pv
$ cm
$ roslaunch navigator_ros pv_robot_navigator_ros.launch
```


