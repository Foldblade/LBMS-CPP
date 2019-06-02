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
string get_ISBN();
