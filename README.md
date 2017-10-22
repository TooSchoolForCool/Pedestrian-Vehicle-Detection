# [ADAS] Pedestrian and Vehicle Detection

This repo is my undergrad capstone project, which is a Vehicle & Pedestrian Detection system and is a part of a vision module for an Advanced Driver Assistance System (ADAS).

This system performed its vehicle/pedestrian detection processes using a single camera mounted at the front of the car. The camera will return a video sequence which contains a sequence of images. By analyzing these images based on some detection/tracking algorithms, the system could an understanding of  surrounding environment.

This program has been tested on two platform: 

1. A PC, which has a 2.2 GHz Intel Core i5 CPU and 4G Memory, with Ubuntu 14.04 installed. On PC it takes 45.06ms to analyze a frame (1280 x 720 resolution) in average;
2. An Embedded platform, a ARM Cortex A9 (1GHz; single core) with Ubuntu 14.04 installed, it takes 588ms to analyze a frame (1280 x 720 resolution) in average.

In the second testbed (i.e., ARM Cortex A9), it is hard to say this program could be run in real-time. However, if we try to run this program on a ARM + GPU or ARM + FGPA platform, this kind of heterogeneous-architecture computation could boost the detection efficiency.

## Demo

Here are some demos of this program. 

*Note: Demo is performed on a Mac*

![2](demo-pic/2.jpg)

![1](demo-pic/1.jpg)

![3](demo-pic/3.jpg)

![5](demo-pic/5.jpg)

![6](demo-pic/6.jpg)

![4](demo-pic/4.jpg)

![7](demo-pic/7.jpg)

![8](demo-pic/8.jpg)



## Overview

For the vehicle detection, I adopted a parallel-connected cascaded [Adaboost](https://en.wikipedia.org/wiki/AdaBoost) classifier, which contains two cascaded Ababoost classifiers with [Haar-like](https://en.wikipedia.org/wiki/Haar-like_feature) feature. One classifier is used for front-car detection, and the other one is used for rear-car detection. In the mean while, each cascaded Ababoost classifier is a series of Adaboost classifier which implemented in a group of decision stump in the low level.

For the pedestrian detection I adopted a Adaboost classifier with [LBP](https://en.wikipedia.org/wiki/Local_binary_patterns) feature and a [Support Vector Machine (SVM)](https://en.wikipedia.org/wiki/Support_vector_machine) with [HOG](https://en.wikipedia.org/wiki/Histogram_of_oriented_gradients) feature in series. Since the HOG feature is time-comsuming, the program runs Adaboost classifier first, and proposes some regions in which it thinks there is likely a pedestrian. Then the program runs SVM to double-check the regions proposed by the first classifier. Only when both of them say there is a pedestrian in that region, the program will be convinced.

For the detection of vehicles passing by on both side, the program utilized a [Optical Flow](https://en.wikipedia.org/wiki/Optical_flow) tracking algorithm. By calculating the optical flow on right-bottom region and left-bottom region, the program will know the relative speed of the moving objects on each side. Thereby, it can determine whether there is a vehicle passing by or not. In more detail, I implemented the Optical Flow tracking algorithm with a [SIFT](https://en.wikipedia.org/wiki/Scale-invariant_feature_transform) feature extractor and [Lucas-Kanade](https://en.wikipedia.org/wiki/Lucas–Kanade_method) method.

**Zeyu Zhang @Hunan University, China**