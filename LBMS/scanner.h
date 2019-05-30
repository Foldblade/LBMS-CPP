/*****************************************************************************
 * This file is part of LBMS-CPP.
 *  @file	scanner.h
 *  @brief	��OpenCV��Zbarɨ�����ļ򵥷�װ
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
 * @brief ��ȡISBN13
 *
 * @param
 *     ��
 *
 * @return
 *     string ��ȡ��ISBN13
 */
string get_ISBN() {
	Json config(".config.json"); // ��ȡJson�ļ�
	int cameraId = config.doc["cameraid"].GetInt(); // ��ȡcameraid
	// ������ͷ��������ͷ�л�ȡ��Ƶ
	string isbn13 = "δ�ܶ�ȡ��ISBN����";
	CvCapture* capture = cvCreateCameraCapture(cameraId);
	// ����ͷ������
	if (!capture) {
		QMessageBox::warning(NULL, QString::fromLocal8Bit("������"), QString::fromLocal8Bit("δ��⵽����ͷ���볢���޸�����ͷID���������С�"), QMessageBox::Ok);
	}
	// �������ڣ���Ϊ"Scanner"���Զ�������С
	cvNamedWindow("Scanner", CV_WINDOW_AUTOSIZE);
	// �Ҷ�ͼ
	IplImage* grayFrame = 0;
	// ����zbarͼ��ɨ����
	ImageScanner scanner;
	// ����zbarͼƬɨ��������ȡ13λISBN
	scanner.set_config(ZBAR_ISBN13, ZBAR_CFG_ENABLE, 1);
	while (1)
	{
		// ������ͷ��ץȡһ֡
		IplImage* frame = cvQueryFrame(capture);
		// ͼ��Ϊ��
		if (frame)
		{
			// ����Ҷ�ͼû�д������ʹ���һ����ԭͼһ����С�ĻҶ�ͼ��8λɫ���ͨ����
			if (!grayFrame) {
				grayFrame = cvCreateImage(cvGetSize(frame), IPL_DEPTH_8U, 1);
			}
			// ԭͼת�Ҷ�ͼ
			cvCvtColor(frame, grayFrame, CV_BGR2GRAY);
			// ��ʾ�Ҷ�ͼ
			cvShowImage("Scanner", grayFrame);
			// ����zbarͼ��
			Image image(frame->width, frame->height, "Y800", grayFrame->imageData, frame->width * frame->height);
			// �����в�ֹһ���룬ɨ��ͼ��ʶ���ά�롢��ȡ����
			int symbolCount = scanner.scan(image);
			// ��ȡ��һ����ά��
			Image::SymbolIterator symbol = image.symbol_begin();
			// �����в�ֹһ���룬��������ʶ������Ķ�ά��
			while (symbolCount--)
			{
				//  �����ά������
				//  cout << "'" << symbol->get_data() << "'" << endl;
				// ��ȡ��λ�����
				int pointCount = symbol->get_location_size();
				// �������ж�λ��
				for (int i = 0; i < pointCount; i++) {
					if (symbol->get_type_name() == "ISBN-13") { // �����ά��������ISBN13
						isbn13 = symbol->get_data(); // ��ȡ����
						// cout << isbn13 << endl;
						goto stop; // ��ȡ���������ת��stop����ѭ��
					}
				}
				// ��һ����ά��
				++symbol;
			}
		}
		// ����ESC���˳�
		if (cvWaitKey(50) == 27) {
			break;
		}
		// ������Ƴ�
		if (!cvGetWindowHandle("Scanner"))
		{
			break;
		}
	}
stop:
	// �ͷŻҶ�ͼ
	cvReleaseImage(&grayFrame);
	// ���ٴ���
	cvDestroyWindow("Scanner");
	// �ͷ��ڴ�
	cvReleaseCapture(&capture);
	// ����ISBN13�ַ���
	return isbn13;
}
