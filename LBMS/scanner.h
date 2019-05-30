/*****************************************************************************
 * This file is part of LBMS-CPP.
 *  @file	scanner.h
 *  @brief	对OpenCV和Zbar扫码器的简单封装
 *  @author	F.B.
 */
#pragma once
#pragma warning(disable : 4996)
#include <opencv/cv.h>
#include <opencv/highgui.h>
#include "QMessageBox"
#include <zbar.h>
#include <iostream>
#include <string>
#include "json.h"

using namespace std;
using namespace zbar;

/**
 * @brief 获取ISBN13
 *
 * @param
 *     无
 *
 * @return
 *     string 获取的ISBN13
 */
string get_ISBN() {
	Json config(".config.json"); // 读取Json文件
	int cameraId = config.doc["cameraid"].GetInt(); // 提取cameraid
	// 打开摄像头，从摄像头中获取视频
	string isbn13 = "未能读取到ISBN条码";
	CvCapture* capture = cvCreateCameraCapture(cameraId);
	// 摄像头不存在
	if (!capture) {
		QMessageBox::warning(NULL, QString::fromLocal8Bit("出错了"), QString::fromLocal8Bit("未检测到摄像头。请尝试修改摄像头ID或重新运行。"), QMessageBox::Ok);
	}
	// 创建窗口，名为"Scanner"，自动调整大小
	cvNamedWindow("Scanner", CV_WINDOW_AUTOSIZE);
	// 灰度图
	IplImage* grayFrame = 0;
	// 创建zbar图像扫描器
	ImageScanner scanner;
	// 配置zbar图片扫描器，采取13位ISBN
	scanner.set_config(ZBAR_ISBN13, ZBAR_CFG_ENABLE, 1);
	while (1)
	{
		// 从摄像头中抓取一帧
		IplImage* frame = cvQueryFrame(capture);
		// 图像不为空
		if (frame)
		{
			// 如果灰度图没有创建，就创建一个和原图一样大小的灰度图（8位色深，单通道）
			if (!grayFrame) {
				grayFrame = cvCreateImage(cvGetSize(frame), IPL_DEPTH_8U, 1);
			}
			// 原图转灰度图
			cvCvtColor(frame, grayFrame, CV_BGR2GRAY);
			// 显示灰度图
			cvShowImage("Scanner", grayFrame);
			// 创建zbar图像
			Image image(frame->width, frame->height, "Y800", grayFrame->imageData, frame->width * frame->height);
			// 可能有不止一个码，扫描图像、识别二维码、获取个数
			int symbolCount = scanner.scan(image);
			// 获取第一个二维码
			Image::SymbolIterator symbol = image.symbol_begin();
			// 可能有不止一个码，遍历所有识别出来的二维码
			while (symbolCount--)
			{
				//  输出二维码内容
				//  cout << "'" << symbol->get_data() << "'" << endl;
				// 获取定位点个数
				int pointCount = symbol->get_location_size();
				// 遍历所有定位点
				for (int i = 0; i < pointCount; i++) {
					if (symbol->get_type_name() == "ISBN-13") { // 如果二维码类型是ISBN13
						isbn13 = symbol->get_data(); // 获取数据
						// cout << isbn13 << endl;
						goto stop; // 获取到条码后跳转到stop跳出循环
					}
				}
				// 下一个二维码
				++symbol;
			}
		}
		// 按了ESC可退出
		if (cvWaitKey(50) == 27) {
			break;
		}
		// 按叉可推出
		if (!cvGetWindowHandle("Scanner"))
		{
			break;
		}
	}
stop:
	// 释放灰度图
	cvReleaseImage(&grayFrame);
	// 销毁窗口
	cvDestroyWindow("Scanner");
	// 释放内存
	cvReleaseCapture(&capture);
	// 返回ISBN13字符串
	return isbn13;
}
