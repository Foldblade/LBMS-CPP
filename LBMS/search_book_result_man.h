#pragma once

#include <QWidget>
#include "ui_search_book_result_man.h"

class search_book_result_man : public QWidget
{
	Q_OBJECT

public:
	search_book_result_man(QWidget *parent = Q_NULLPTR);
	~search_book_result_man();
	void go();
	void receive_book_data(QString isbn, QString book_name, QString writer, QString publishing_house);   // 用来接收数据

private:
	Ui::search_book_result_man ui;
private slots:
	void slot1(); // 返回
	void slot2(); // 确认修改
	void slot3(); // 进入修改界面
};
