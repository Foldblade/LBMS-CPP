#pragma once

#include <QWidget>
#include "ui_fail.h"

class fail : public QWidget
{
	Q_OBJECT

public:
	fail(QWidget *parent = Q_NULLPTR);
	~fail();

private:
	Ui::fail ui;
};
