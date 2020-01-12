# perceptron的架构与运功规划组需要配合的内容

参会人员: 代津, 温从标, 焦健

## 1. 介绍图

![226072181](pic/226072181.jpg)

## 2.讨论问题

1. planned trajectory作为输入的问题, 作为接口预留. 目前避障检测模块作为功能模块库, navigator和perceptron同时调用它.
2. int decision: 表示detection类型, 表示不同模式.
3. 图上的下面10项是技术手段.左边是输入,右边是输出.其中红色的比较急, 明年3月需要完成. (其中运动规划组比较关心precise collision detection.之后会由运动规划与感知组共同开发).
4. 多种避障模式set ROI mode.数据结构接口设计.本周完成.jimmy出初稿, 之后从标组织会议讨论.
5. 标哥联系组内开发人员确定perceptron开发时间点.

## 3. action item

1. 标哥联系组内开发人员确定perceptron开发时间点.
2. jimmy提供set ROI mode.数据结构接口设计初稿, 之后再进行讨论
3. 从标组织会议进行讨论.