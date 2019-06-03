#pragma once

#include <QWidget>
#include "ui_edit_book.h"

class edit_book : public QWidget
{
	Q_OBJECT

public:
	edit_book(QWidget *parent = Q_NULLPTR);
	~edit_book();
	/* Below works are modified by F.B. */
	void receive_book_data(QString isbn, QString title, QString writer, QString publisher, QString many, QString inside, QString outside, QString ID);   // 用来接收数据
	void go();

private:
	Ui::edit_book ui;
private slots:
	void saving();
	void back();
	void deleting();

};
