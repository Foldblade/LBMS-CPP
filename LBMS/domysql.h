﻿/*****************************************************************************
 * This file is part of LBMS-CPP.
 *  @file	domysql.h
 *  @brief	对MySQL Connecter C++的简单封装
 *  @author	F.B.
 */

#pragma once
#include <iostream>  
#include <map>  
#include <string>  
#include <memory>  
#include <boost/any.hpp> 
#include <mysql_driver.h>
#include <mysql_connection.h>  
#include <cppconn/driver.h>
#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h>  
#include <cppconn/metadata.h> 
#include <cppconn/exception.h>


using namespace std;
using namespace sql;
using namespace boost;

#pragma comment(lib, "mysqlcppconn.lib")  

class Info {
public:
	string host, user, password, database;
	Info();
	Info(string host, string user, string password, string database);
	void update_info(string host, string user, string password, string database);
};

class Operate : public Info {
public:
	// MySQL初始化
	mysql::MySQL_Driver* driver;
	Connection* con;
	Statement* state;
	ResultSet* res;
	
	int length;// 返回结果行数

	/**
	 * @brief connect(): 连接到远程MySQL数据库
	 *
	 * @param
	 *     无
	 *
	 * @return
	 *     bool true: 成功
	 *     bool false: 失败
	 */
	bool connect();

	map<int, map<string, any> > results;

	/**
	 * @brief get_all_results(): 总查询
	 *
	 * @param
	 *     无
	 *
	 * @return
	 *     无
	 */
	void get_all_results();

	/**
	 * @brief exec(string sqlSentence): 执行SQL语句（无返回）
	 *
	 * @param
	 *     string sqlSentence: 要执行的SQL语句
	 *
	 * @return
	 *     bool true: 成功
	 *     bool false: 失败
	 */
	bool exec(string sqlSentence);

	/**
	 * @brief exec(string sqlSentence): 进行SQL语句查询（有返回）
	 *
	 * @param
	 *     string sqlSentence: 要查询的SQL语句
	 *
	 * @return
	 *     bool true: 成功
	 *     bool false: 失败
	 */
	bool exec_with_return(string sqlSentence);

	/**
	 * @brief addBook(string ISBN, string title, string author, string publisher, int many): 管理员添加图书
	 *
	 * @param
	 *     string ISBN: ISBN号
	 *     string title: 书名
	 *     string author: 作者
	 *     string publisher: 出版社
	 *     int many: 数量
	 *
	 * @return
	 *     bool true: 成功
	 *     bool false: 失败
	 */
	bool addBook(string ISBN, string title, string author, string publisher, int many);

	/**
	 * @brief searchBook(string ISBN, string title, string author, string publisher): 搜索图书
	 *
	 * @param
	 *     string ISBN: ISBN号
	 *     string title: 书名
	 *     string author: 作者
	 *     string publisher: 出版社
	 *
	 * @return
	 *     bool true: 成功
	 *     bool false: 失败
	 */
	bool searchBook(string ISBN, string title, string author, string publisher);

	/**
	 * @brief borrow_book(string ISBN): 借书
	 *
	 * @param
	 *     string ISBN: 所借书的ISBN
	 *
	 * @return
	 *     bool true: 成功
	 *     bool false: 失败
	 */
	bool borrow_book(string ISBN);

	/**
	 * @brief return_book(string ISBN): 还书
	 *
	 * @param
	 *     string ISBN: 所还书的ISBN
	 *
	 * @return
	 *     bool true: 成功
	 *     bool false: 失败
	 */
	bool return_book(string ISBN);

	/**
	 * @brief modify_book(int id): 还书
	 *
	 * @param
	 *     int id: 该条记录的id
	 *     string ISBN: 修改后的ISBN
	 *     string title: 修改后的标题
	 *     string author: 修改后的作者
	 *     string publisher: 修改后的出版社
	 *     int many: 修改后的总数
	 *     int inside: 修改后的馆藏数
	 *     int outside: 修改后的借出书
	 *
	 * @return
	 *     bool true: 成功
	 *     bool false: 失败
	 */
	bool modify_book(int id, string ISBN, string title, string author, string publisher, int many, int inside, int outside);


	~Operate() {
		if (con != 0)
		{
			delete res;
			delete state;
			delete con;
		}
	}
};

/*
Examples：
————————————————————————
```
using namespace std;
using namespace sql;
using namespace boost;
// skip some code here
Operate p;
	if (p.connect()) {
		p.get_all_results();
		for (int i = 0; i < p.length; i++) {
			cout << any_cast<string>(p.results[i]["ISBN"]) << "\t" << any_cast<int>(p.results[i]["many"]) << endl;
		}
		p.addBook("9787220112775", "平安朝的生活与文学", "[日] 池田龟鉴", "后浪丨四川人民出版社", 2);
		p.borrow_book("9787220112775");
		p.return_book("9787220112775");
		p.modify_book(15, "9787220112775", "平安朝的生活与文学", "[日] 池田龟鉴", "后浪丨四川人民出版社", 4, 3, 1);
	}
	else {
		cout << "ERROR" << endl;
	}
```

*/