#pragma once

#include <QWidget>
#include "ui_borrow_return_book.h"

class borrow_return_book : public QWidget
{
	Q_OBJECT

public:
	borrow_return_book(QWidget *parent = Q_NULLPTR);
	~borrow_return_book();

private:
	Ui::borrow_return_book ui;
private slots:
	void slot1(); // 回到管理中心
	void slot2(); // 借书
	void slot3(); // 还书
	void slot4(); // 开启扫码
};
