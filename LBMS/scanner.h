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
string get_ISBN();
