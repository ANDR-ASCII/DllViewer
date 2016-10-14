#ifndef DLLVIEWER_H
#define DLLVIEWER_H

#include <QtWidgets/QMainWindow>
#include "ui_dllviewer.h"

class DllViewer : public QMainWindow
{
	Q_OBJECT

public:
	DllViewer(QWidget *parent = 0);
	~DllViewer();

private:
	Ui::DllViewerClass ui;
};

#endif // DLLVIEWER_H
