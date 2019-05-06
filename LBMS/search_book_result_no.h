#pragma once

#include <QWidget>
#include "ui_search_book_result_no.h"

class search_book_result_no : public QWidget
{
	Q_OBJECT

public:
	search_book_result_no(QWidget *parent = Q_NULLPTR);
	~search_book_result_no();

private:
	Ui::search_book_result_no ui;
private slots:
	void slot1();
};
