#pragma once

#include <QWidget>
#include "ui_edit_book.h"

class edit_book : public QWidget
{
	Q_OBJECT

public:
	edit_book(QWidget *parent = Q_NULLPTR);
	~edit_book();

private:
	Ui::edit_book ui;
private slots:
	void saving();
	void back();
	void deleting();

};
