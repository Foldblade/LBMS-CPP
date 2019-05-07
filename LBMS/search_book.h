#pragma once

#include <QWidget>
#include "ui_search_book.h"
#include "search_book.h"
#include "search_book_result_no.h"
class search_book : public QWidget
{
	Q_OBJECT

public:
	search_book(QWidget *parent = Q_NULLPTR);
	~search_book();

private:
	Ui::search_book ui;
	search_book_result_no* x;
private slots:
	void slot1();//返回功能页
	void slot2();//查询图书信息
};
