#pragma once

#include <QWidget>
#include "ui_search_book_result_man.h"

class search_book_result_man : public QWidget
{
	Q_OBJECT

public:
	search_book_result_man(QWidget *parent = Q_NULLPTR);
	~search_book_result_man();

private:
	Ui::search_book_result_man ui;
private slots:
	void slot1();
	void slot2();
};
