#pragma once

#include <QWidget>
#include "ui_scan_input.h"

class scan_input : public QWidget
{
	Q_OBJECT

public:
	scan_input(QWidget *parent = Q_NULLPTR);
	~scan_input();

private:
	Ui::scan_input ui;
private slots:
	void slot1();
	void slot2();
	void slot3();
};
