/*****************************************************************************
 * This file is part of LBMS-CPP.
 *  @file	json.h
 *  @brief	对json的简单封装
 *  @author	F.B.
 */
#pragma once
#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"
#include "rapidjson/istreamwrapper.h"
#include "rapidjson/ostreamwrapper.h"
#include <fstream>
#include <string>
#include <iostream>

using namespace rapidjson;
using namespace std;

/**
 * @brief class Json：对rapidJson功能的简单封装
 */
class Json {
public:
	string jsonFileName;
	Document doc;
	StringBuffer buffer;

	/**
     * @brief 函数Json构造@brief 函数（含参）: 打开Json文件，并解析之
	 *
	 * @param
     *     string jsonFileName: json文件名、
	 *
	 * @return
	 *     无返回值
     */
	Json(string jsonFileName);

	/**
	 * @brief 函数SaveJson: 保存为json文件
	 *
	 * @param
	 *     string saveFileName: json文件名
	 *
	 * @return
	 *     无
	 */
	void SaveJson(string saveFileName);

	/**
	 * @brief 函数ToString: json转为string
	 *
	 * @param
	 *     无
	 *
	 * @return
	 *     string outString: json转为string的结果
	 */
	string ToString();

	/**
	 * @brief 函数ToString: json转为string
	 * 
	 * @param
	 *     Json json: 存在的json类对象
	 * 
	 * @return
	 *     string outString: json转为string的结果
	 */
	string ToString(Json json);

	/**
	 * @brief 函数ToString: json转为string
	 *
	 * @param
	 *     string jsonFileName: json文件名
	 *
	 * @return
	 *     string outString: json文件转为string的结果
	 */
	string ToString(string jsonFileName);

	/**
	 * @brief 函数StrToString: string转为json
	 *
	 * @param
	 *     string str: 要转换为json对象的string
	 *
	 * @return
	 *     将string解析到Json类对象中，无
	 */
	void StrToJson(string str);
	void modify(string key, string value);
	void update();
};