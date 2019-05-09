#pragma once
#include "json.h"

using namespace rapidjson;
using namespace std;

Json::Json(string jsonFileName) { // ����json
	// 1. �� JSON ������ DOM��
	ifstream ifs(jsonFileName);
	IStreamWrapper isw(ifs);
	doc.ParseStream(isw);
	// 2. ���� DOM �����޸ġ�
	// Value& s = doc["stars"];
	// s.SetInt(s.GetInt() + 1);
	// 3. �� DOM ת����stringify���� JSON��
	Writer<StringBuffer> writer(buffer);
	doc.Accept(writer);
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
