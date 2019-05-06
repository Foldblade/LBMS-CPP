#pragma once

#include <QWidget>
#include "ui_success.h"

class success : public QWidget
{
	Q_OBJECT

public:
	success(QWidget *parent = Q_NULLPTR);
	~success();

private:
	Ui::success ui;
};
