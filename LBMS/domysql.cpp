/*****************************************************************************
 * This file is part of LBMS-CPP.
 *  @file	domysql.cpp
 *  @brief	对MySQL Connecter C++的简单封装
 *  @author	F.B.
 */

#include <iostream>  
#include <map>  
#include <string>  
#include <memory>  

#include <mysql_driver.h>
#include <mysql_connection.h>  
#include <cppconn/driver.h>
#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h>  
#include <cppconn/metadata.h> 
#include <cppconn/exception.h>
#include "json.h"
#include "domysql.h"
using namespace std;
using namespace sql;

#pragma comment(lib, "mysqlcppconn.lib")  

Json sqlconfig(".sql_config.json");

Info::Info() {
	this->host = sqlconfig.doc["host"].GetString();
	this->user = sqlconfig.doc["user"].GetString();
	this->password = sqlconfig.doc["password"].GetString();
	this->database = sqlconfig.doc["database"].GetString();
}

Info::Info(string host, string user, string password, string database) {
	this->host = host;
	this->user = user;
	this->password = password;
	this->database = database;
}
void Info::update_info(string host, string user, string password, string database) {
	this->host = host;
	this->user = user;
	this->password = password;
	this->database = database;
}


bool Operate::connect() {
	try
	{
		driver = sql::mysql::get_mysql_driver_instance();
		con = driver->connect(host.c_str(), user.c_str(), password.c_str());
		state = con->createStatement();

		state->execute(("USE " + database).c_str());
		state->execute("SET NAMES GBK");
		return true;
	}
	catch (sql::SQLException & e) {
		cout << "# ERR: SQLException in " << __FILE__;
		cout << "(" << __FUNCTION__ << ") on line "
			<< __LINE__ << endl;
		cout << "# ERR: " << e.what();
		cout << " (MySQL error code: " << e.getErrorCode();
		cout << ", SQLState: " << e.getSQLState() << " )" << endl;
		return false;
	}
}

void Operate::get_all_results() {
	res = state->executeQuery("SELECT * FROM `library`");
	int cnt = 0;
	while (res->next()) {
		results[cnt]["ISBN"] = string(res->getString("ISBN").c_str());
		results[cnt]["title"] = string(res->getString("title").c_str());
		results[cnt]["author"] = string(res->getString("author").c_str());
		results[cnt]["publisher"] = string(res->getString("publisher").c_str());
		results[cnt]["many"] = res->getInt("many");
		results[cnt]["inside"] = res->getInt("inside");
		results[cnt]["outside"] = res->getInt("outside");
		results[cnt]["id"] = res->getInt("id");
		cnt++;
	}
	length = cnt;
}

bool Operate::exec(string sqlSentence) {
	try {
		state->execute(sqlSentence.c_str());
		return true;
	}
	catch (sql::SQLException & e) {
		cout << "# ERR: SQLException in " << __FILE__;
		cout << "(" << __FUNCTION__ << ") on line "
			<< __LINE__ << endl;
		cout << "# ERR: " << e.what();
		cout << " (MySQL error code: " << e.getErrorCode();
		cout << ", SQLState: " << e.getSQLState() << " )" << endl;
		return false;
	}
}

bool Operate::exec_with_return(string sqlSentence) { // 注意，SQL语句必须是"SELETE * FROM"，选择全部的
	try {
		res = state->executeQuery(sqlSentence.c_str());
		int cnt = 0;
		while (res->next()) {
			results[cnt]["ISBN"] = string(res->getString("ISBN").c_str());
			results[cnt]["title"] = string(res->getString("title").c_str());
			results[cnt]["author"] = string(res->getString("author").c_str());
			results[cnt]["publisher"] = string(res->getString("publisher").c_str());
			results[cnt]["many"] = res->getInt("many");
			results[cnt]["inside"] = res->getInt("inside");
			results[cnt]["outside"] = res->getInt("outside");
			results[cnt]["id"] = res->getInt("id");
			cnt++;
		}
		length = cnt;
		return true;
	}
	catch (sql::SQLException & e) {
		cout << "# ERR: SQLException in " << __FILE__;
		cout << "(" << __FUNCTION__ << ") on line "
			<< __LINE__ << endl;
		cout << "# ERR: " << e.what();
		cout << " (MySQL error code: " << e.getErrorCode();
		cout << ", SQLState: " << e.getSQLState() << " )" << endl;
		return false;
	}
}

bool Operate::addBook(string ISBN, string title, string author, string publisher, int many) {
	try {
		int inside = many;
		string execSentence = "INSERT INTO `library` (`ISBN`, `title`, `author`, `publisher`, `many`, `inside`)"
			"VALUES ('" + ISBN + "', '" + title + "', '" + author + "', '" + publisher + "', '" + to_string(many) + "', '" + to_string(inside) + "')";
		state->execute(execSentence.c_str());
		return true;
	}
	catch (sql::SQLException & e) {
		cout << "# ERR: SQLException in " << __FILE__;
		cout << "(" << __FUNCTION__ << ") on line "
			<< __LINE__ << endl;
		cout << "# ERR: " << e.what();
		cout << " (MySQL error code: " << e.getErrorCode();
		cout << ", SQLState: " << e.getSQLState() << " )" << endl;
		return false;
	}
}

bool Operate::searchBook(string ISBN, string title, string author, string publisher) {
	try {
		string execSentence = "SELECT *  FROM `library` "
			"WHERE `ISBN` LIKE '%" + ISBN + "%' AND `title` LIKE '%" + title + 
			"%' AND `author` LIKE '%" + author + "%' AND `publisher` LIKE '%" + publisher + "%'";
		res = state->executeQuery(execSentence.c_str());
		int cnt = 0;
		while (res->next()) {
			results[cnt]["ISBN"] = string(res->getString("ISBN").c_str());
			results[cnt]["title"] = string(res->getString("title").c_str());
			results[cnt]["author"] = string(res->getString("author").c_str());
			results[cnt]["publisher"] = string(res->getString("publisher").c_str());
			results[cnt]["many"] = res->getInt("many");
			results[cnt]["inside"] = res->getInt("inside");
			results[cnt]["outside"] = res->getInt("outside");
			results[cnt]["id"] = res->getInt("id");
			cnt++;
		}
		length = cnt;
		return true;
	}
	catch (sql::SQLException& e) {
		cout << "# ERR: SQLException in " << __FILE__;
		cout << "(" << __FUNCTION__ << ") on line "
			<< __LINE__ << endl;
		cout << "# ERR: " << e.what();
		cout << " (MySQL error code: " << e.getErrorCode();
		cout << ", SQLState: " << e.getSQLState() << " )" << endl;
		return false;
	}
}

bool Operate::borrow_book(string ISBN) {
	try {
		string execSentence = "SELECT *  FROM `library` WHERE `ISBN` = '" + ISBN + "'";
		res = state->executeQuery(execSentence.c_str());
		int many, inside, outside;
		while (res->next()) {
			many = res->getInt("many");
			inside = res->getInt("inside");
			outside = res->getInt("outside");
		}
		outside = outside + 1;
		inside = many - outside;
		execSentence = "UPDATE `library` SET `inside` = '" + to_string(inside) + "', `outside` = '" + to_string(outside) +
			"' WHERE `library`.`ISBN` = '" + ISBN + "' ";
		state->execute(execSentence.c_str());
		return true;
	}
	catch (sql::SQLException & e) {
		cout << "# ERR: SQLException in " << __FILE__;
		cout << "(" << __FUNCTION__ << ") on line "
			<< __LINE__ << endl;
		cout << "# ERR: " << e.what();
		cout << " (MySQL error code: " << e.getErrorCode();
		cout << ", SQLState: " << e.getSQLState() << " )" << endl;
		return false;
	}
}

bool Operate::return_book(string ISBN) {
	try {
		string execSentence = "SELECT *  FROM `library` WHERE `ISBN` = '" + ISBN + "'";
		res = state->executeQuery(execSentence.c_str());
		int many, inside, outside;
		while (res->next()) {
			many = res->getInt("many");
			inside = res->getInt("inside");
			outside = res->getInt("outside");
		}
		outside = outside - 1;
		inside = many - outside;
		execSentence = "UPDATE `library` SET `inside` = '" + to_string(inside) + "', `outside` = '" + to_string(outside) + 
			"' WHERE `library`.`ISBN` = '" + ISBN + "' ";
		state->execute(execSentence.c_str());
		return true;
	}
	catch (sql::SQLException & e) {
		cout << "# ERR: SQLException in " << __FILE__;
		cout << "(" << __FUNCTION__ << ") on line "
			<< __LINE__ << endl;
		cout << "# ERR: " << e.what();
		cout << " (MySQL error code: " << e.getErrorCode();
		cout << ", SQLState: " << e.getSQLState() << " )" << endl;
		return false;
	}
}

bool Operate::modify_book(int id, string ISBN, string title, string author, string publisher, int many, int inside, int outside) {
	try {
		string execSentence = "UPDATE `library` SET `ISBN` = '" + ISBN + "', `title` = '" + title + "', `author` = '" + author + 
			"', `publisher` = '" + publisher + "', `many` = '" + to_string(many) + "', `inside`='" + to_string(inside) + "', `outside`='" + to_string(outside) + 
			"' WHERE `library`.`id` = '" + to_string(id) + "' ";
		state->execute(execSentence.c_str());
		return true;
	}
	catch (sql::SQLException & e) {
		cout << "# ERR: SQLException in " << __FILE__;
		cout << "(" << __FUNCTION__ << ") on line "
			<< __LINE__ << endl;
		cout << "# ERR: " << e.what();
		cout << " (MySQL error code: " << e.getErrorCode();
		cout << ", SQLState: " << e.getSQLState() << " )" << endl;
		return false;
	}
}