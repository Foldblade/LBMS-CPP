#pragma once
#ifndef QTGUIAPPLICATION5_H
#define QTGUIAPPLICATION5_H


#include <QtWidgets/QMainWindow>
#include  "ui_QtGuiApplication5.h"
#include  "QtGuiClass.h"
#include  "search_book.h"

class QtGuiApplication5 : public QMainWindow
{
	Q_OBJECT

public:
	QtGuiApplication5(QWidget *parent = Q_NULLPTR);
	~QtGuiApplication5();
private:
	Ui::QtGuiApplication5Class ui;
	QtGuiClass *x;
	search_book* x1;
private slots:
	void slot1();
	void slot2();
};
#endif // !QTGUIAPPLICATION5_H