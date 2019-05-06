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
	void slot1();//back
	void slot2();//enter
};
