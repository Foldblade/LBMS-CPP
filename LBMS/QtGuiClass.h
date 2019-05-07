#pragma once
#ifndef QTGUICLASS_H
#define QTGUICLASS_H

#include <QWidget>
#include "ui_QtGuiClass.h"
#include "adminitor_con.h"
#include "fail.h"

class QtGuiClass : public QWidget
{
	Q_OBJECT

public:
	QtGuiClass(QWidget *parent = Q_NULLPTR);
	~QtGuiClass();
	adminitor_con* x;//为了节省后面一行（当作没看见注释
	fail* fa;//为了节省后面一行（当作没看见注释
private:
	Ui::QtGuiClass ui;

private slots:
	void slot1();//返回登陆界面
	void slot2();//登陆
};
#endif // !QTGUICLASS
