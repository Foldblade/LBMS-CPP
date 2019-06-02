#pragma once

#include <QWidget>
#include "ui_search_book_man.h"

class search_book_man : public QWidget
{
	Q_OBJECT

public:
	search_book_man(QWidget *parent = Q_NULLPTR);
	~search_book_man();

private:
	Ui::search_book_man ui;
private slots:
	void slot1(); // ∑µªÿ
	void slot2(); // ≤È—Ø
};
