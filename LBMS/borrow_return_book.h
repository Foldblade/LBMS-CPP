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
	void slot1(); // �ص���������
	void slot2(); // ����
	void slot3(); // ����
	void slot4(); // ����ɨ��
};
