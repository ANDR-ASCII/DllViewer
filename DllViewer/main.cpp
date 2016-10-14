#include "stdafx.h"
#include "dllviewer.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	DllViewer w;
	w.show();
	return a.exec();
}
