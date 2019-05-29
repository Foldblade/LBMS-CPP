/*****************************************************************************
 * This file is part of LBMS-CPP.
 *  @file	json.h
 *  @brief	��json�ļ򵥷�װ
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
 * @brief class Json����rapidJson���ܵļ򵥷�װ
 */
class Json {
public:
	string jsonFileName;
	Document doc;
	StringBuffer buffer;

	/**
     * @brief ����Json����@brief ���������Σ�: ��Json�ļ���������֮
	 *
	 * @param
     *     string jsonFileName: json�ļ�����
	 *
	 * @return
	 *     �޷���ֵ
     */
	Json(string jsonFileName);

	/**
	 * @brief ����SaveJson: ����Ϊjson�ļ�
	 *
	 * @param
	 *     string saveFileName: json�ļ���
	 *
	 * @return
	 *     ��
	 */
	void SaveJson(string saveFileName);

	/**
	 * @brief ����ToString: jsonתΪstring
	 *
	 * @param
	 *     ��
	 *
	 * @return
	 *     string outString: jsonתΪstring�Ľ��
	 */
	string ToString();

	/**
	 * @brief ����ToString: jsonתΪstring
	 * 
	 * @param
	 *     Json json: ���ڵ�json�����
	 * 
	 * @return
	 *     string outString: jsonתΪstring�Ľ��
	 */
	string ToString(Json json);

	/**
	 * @brief ����ToString: jsonתΪstring
	 *
	 * @param
	 *     string jsonFileName: json�ļ���
	 *
	 * @return
	 *     string outString: json�ļ�תΪstring�Ľ��
	 */
	string ToString(string jsonFileName);

	/**
	 * @brief ����StrToString: stringתΪjson
	 *
	 * @param
	 *     string str: Ҫת��Ϊjson�����string
	 *
	 * @return
	 *     ��string������Json������У���
	 */
	void StrToJson(string str);
	void modify(string key, string value);
	void update();
};