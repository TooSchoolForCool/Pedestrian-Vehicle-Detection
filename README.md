# [ADAS] Pedestrian and Vehicle Detection

This repo is my undergrad capstone project, which is a Vehicle & Pedestrian Detection system and is a part of a vision module for an Advanced Driver Assistance System (ADAS).

This system performed its vehicle/pedestrian detection processes using a single camera mounted at the front of the car. The camera will return a video sequence which contains a sequence of images. By analyzing these images based on some detection/tracking algorithms, the system could an understanding of  surrounding environment.

This program has been tested on two platform: 

1. A PC, which has a 2.2 GHz Intel Core i5 CPU and 4G Memory, with Ubuntu 14.04 installed. On PC it takes 45.06ms to analyze a frame (1280 $\times$ 720 resolution) in average;
2. An Embedded platform, a ARM Cortex A9 (1GHz; single core) with Ubuntu 14.04 installed, it takes 588ms to analyze a frame (1280 $\times$ 720 resolution) in average.

In the second testbed (i.e., ARM Cortex A9), it is hard to say this program could be run in real-time. However, if we try to run this program on a ARM + GPU or ARM + FGPA platform, this kind of heterogeneous-architecture computation could boost the detection efficiency.

## Demo

Here are some demos of this program.![2](demo-pic/2.jpg)

![1](demo-pic/1.jpg)

![3](demo-pic/3.jpg)

![5](demo-pic/5.jpg)

![6](demo-pic/6.jpg)

![4](demo-pic/4.jpg)

![7](demo-pic/7.jpg)

![8](demo-pic/8.jpg)



## Overview



The vehicle detection algorithms/models can recoginize motorised vehicles such as cars, trucks, in both day and night conditions.

The pedestrian detection algorithms can recoginize moving people or static people stood with some specific postures.


*Note: For some reason I cannot provide all my xml classifier configuration files.*

**Zeyu Zhang @Hunan University, China**