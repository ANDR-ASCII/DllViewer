#pragma once
#include <QWidget>
#include "ui_generalnotification.h"

class GeneralNotification : public QWidget 
{
	Q_OBJECT

public:
	GeneralNotification(QWidget * parent = nullptr);

private:
	Ui::GeneralNotification ui;
};
