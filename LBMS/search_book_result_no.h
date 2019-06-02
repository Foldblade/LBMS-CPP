#pragma once

#include <QWidget>
#include "ui_search_book_result_no.h"

class search_book_result_no : public QWidget
{
	Q_OBJECT

public:
	search_book_result_no(QWidget *parent = Q_NULLPTR);
	~search_book_result_no();
	void go();
	void send_book_data(QString isbn, QString book_name, QString writer, QString publishing_house);   //用来接收数据的信号

private:
	Ui::search_book_result_no ui;

private slots:
	void slot1(); // 返回
	
};
