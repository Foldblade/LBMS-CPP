#pragma once
#include "json.h"

using namespace rapidjson;
using namespace std;

Json::Json(string jsonFileName) { // ����json
	// 1. �� JSON ������ DOM��
	ifstream ifs(jsonFileName);
	IStreamWrapper isw(ifs);
	doc.ParseStream(isw);
}

void Json::SaveJson(string saveFileName) { // ����json
	ofstream ofs(saveFileName);
	OStreamWrapper osw(ofs);
	Writer<OStreamWrapper> writer(osw);
	doc.Accept(writer);
}

string Json::ToString() {
	string outString = buffer.GetString();
	return outString;
}

string Json::ToString(Json json) {
	string outString = json.buffer.GetString();
 	return outString;
}
 
string Json::ToString(string jsonFileName) {
	Json json(jsonFileName);
	string outString = json.buffer.GetString();
	return outString;
}

void Json::StrToJson(string str) {
	const char* json = str.c_str();
	doc.Parse(json);
}

void Json::strModify(string key, string value) {
	Value& s = doc[key.c_str()];
	s.SetString(value.c_str(), doc.GetAllocator());
	/* ˵ʵ�����ﲻ̫��
		�ĵ���
		http://rapidjson.org/zh-cn/classrapidjson_1_1_generic_value.html#a3e930bffb40a78e570e3deef461f0532
		http://rapidjson.org/zh-cn/classrapidjson_1_1_generic_document.html#ad92c6cd025d411258d1f2ad890e2ee3f
	*/
}

void Json::update() {
	// 3. �� DOM ת����stringify���� JSON��
	Writer<StringBuffer> writer(buffer);
	doc.Accept(writer);
}