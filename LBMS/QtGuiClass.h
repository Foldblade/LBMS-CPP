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
	adminitor_con* x;
	fail* fa;
private:
	Ui::QtGuiClass ui;

private slots:
	void slot1();
	void slot2();
};
#endif // !QTGUICLASS
