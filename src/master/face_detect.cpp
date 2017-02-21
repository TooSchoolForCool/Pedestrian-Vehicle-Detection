#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/objdetect/objdetect.hpp>

using namespace cv;
using namespace std;

void detectAndDraw( Mat& img, CascadeClassifier& cascade,
                   CascadeClassifier& nestedCascade,
                   double scale, bool tryflip );

int main()
{
    //VideoCapture cap(0);    //打开默认摄像头
    //if(!cap.isOpened())
    //{
    //    return -1;
    //}
    Mat frame;
    Mat edges;

    CascadeClassifier cascade, nestedCascade;
    bool stop = false;
    //训练好的文件名称，放置在可执行文件同目录下
    cascade.load("D:\\opencv\\sources\\data\\haarcascades\\haarcascade_frontalface_alt.xml");
    nestedCascade.load("D:\\opencv\\sources\\data\\haarcascades\\haarcascade_eye.xml");
    frame = imread("E:\\tmpimg\\hezhao.jpg");
    detectAndDraw( frame, cascade, nestedCascade,2,0 );
    waitKey();
    //while(!stop)
    //{
    //    cap>>frame;
    //    detectAndDraw( frame, cascade, nestedCascade,2,0 );
    //    if(waitKey(30) >=0)
    //        stop = true;
    //}
    return 0;
}
void detectAndDraw( Mat& img, CascadeClassifier& cascade,
                   CascadeClassifier& nestedCascade,
                   double scale, bool tryflip )
{
    int i = 0;
    double t = 0;
    //建立用于存放人脸的向量容器
    vector<Rect> faces, faces2;
    //定义一些颜色，用来标示不同的人脸
    const static Scalar colors[] =  {
        CV_RGB(0,0,255),
        CV_RGB(0,128,255),
        CV_RGB(0,255,255),
        CV_RGB(0,255,0),
        CV_RGB(255,128,0),
        CV_RGB(255,255,0),
        CV_RGB(255,0,0),
        CV_RGB(255,0,255)} ;
    //建立缩小的图片，加快检测速度
    //nt cvRound (double value) 对一个double型的数进行四舍五入，并返回一个整型数！
    Mat gray, smallImg( cvRound (img.rows/scale), cvRound(img.cols/scale), CV_8UC1 );
    //转成灰度图像，Harr特征基于灰度图
    cvtColor( img, gray, CV_BGR2GRAY );
    imshow("灰度",gray);
    //改变图像大小，使用双线性差值
    resize( gray, smallImg, smallImg.size(), 0, 0, INTER_LINEAR );
    imshow("缩小尺寸",smallImg);
    //变换后的图像进行直方图均值化处理
    equalizeHist( smallImg, smallImg );
    imshow("直方图均值处理",smallImg);
    //程序开始和结束插入此函数获取时间，经过计算求得算法执行时间
    t = (double)cvGetTickCount();
    //检测人脸
    //detectMultiScale函数中smallImg表示的是要检测的输入图像为smallImg，faces表示检测到的人脸目标序列，1.1表示
    //每次图像尺寸减小的比例为1.1，2表示每一个目标至少要被检测到3次才算是真的目标(因为周围的像素和不同的窗口大
    //小都可以检测到人脸),CV_HAAR_SCALE_IMAGE表示不是缩放分类器来检测，而是缩放图像，Size(30, 30)为目标的
    //最小最大尺寸
    cascade.detectMultiScale( smallImg, faces,
        1.1, 2, 0
        //|CV_HAAR_FIND_BIGGEST_OBJECT
        //|CV_HAAR_DO_ROUGH_SEARCH
        |CV_HAAR_SCALE_IMAGE
        ,Size(30, 30));
    //如果使能，翻转图像继续检测
    if( tryflip )
    {
        flip(smallImg, smallImg, 1);
        imshow("反转图像",smallImg);
        cascade.detectMultiScale( smallImg, faces2,
            1.1, 2, 0
            //|CV_HAAR_FIND_BIGGEST_OBJECT
            //|CV_HAAR_DO_ROUGH_SEARCH
            |CV_HAAR_SCALE_IMAGE
            ,Size(30, 30) );
        for( vector<Rect>::const_iterator r = faces2.begin(); r != faces2.end(); r++ )
        {
            faces.push_back(Rect(smallImg.cols - r->x - r->width, r->y, r->width, r->height));
        }
    }
    t = (double)cvGetTickCount() - t;
    //   qDebug( "detection time = %g ms\n", t/((double)cvGetTickFrequency()*1000.) );
    for( vector<Rect>::const_iterator r = faces.begin(); r != faces.end(); r++, i++ )
    {
        Mat smallImgROI;
        vector<Rect> nestedObjects;
        Point center;
        Scalar color = colors[i%8];
        int radius;

        double aspect_ratio = (double)r->width/r->height;
        if( 0.75 < aspect_ratio && aspect_ratio < 1.3 )
        {
            //标示人脸时在缩小之前的图像上标示，所以这里根据缩放比例换算回去
            center.x = cvRound((r->x + r->width*0.5)*scale);
            center.y = cvRound((r->y + r->height*0.5)*scale);
            radius = cvRound((r->width + r->height)*0.25*scale);
            circle( img, center, radius, color, 3, 8, 0 );
        }
        else
            rectangle( img, cvPoint(cvRound(r->x*scale), cvRound(r->y*scale)),
            cvPoint(cvRound((r->x + r->width-1)*scale), cvRound((r->y + r->height-1)*scale)),
            color, 3, 8, 0);
        if( nestedCascade.empty() )
            continue;
        smallImgROI = smallImg(*r);
        //同样方法检测人眼
        nestedCascade.detectMultiScale( smallImgROI, nestedObjects,
            1.1, 2, 0
            //|CV_HAAR_FIND_BIGGEST_OBJECT
            //|CV_HAAR_DO_ROUGH_SEARCH
            //|CV_HAAR_DO_CANNY_PRUNING
            |CV_HAAR_SCALE_IMAGE
            ,Size(30, 30) );
        for( vector<Rect>::const_iterator nr = nestedObjects.begin(); nr != nestedObjects.end(); nr++ )
        {
            center.x = cvRound((r->x + nr->x + nr->width*0.5)*scale);
            center.y = cvRound((r->y + nr->y + nr->height*0.5)*scale);
            radius = cvRound((nr->width + nr->height)*0.25*scale);
            circle( img, center, radius, color, 3, 8, 0 );
        }
    }
    imshow( "识别结果", img );
}