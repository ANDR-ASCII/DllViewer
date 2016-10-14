#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_dllviewer.h"

namespace DllViewerApp
{
	class DllViewer : public QMainWindow
	{
		Q_OBJECT

	public:
		DllViewer(QWidget *parent = 0);

	private:
		Ui::DllViewerClass ui;
	};
}
