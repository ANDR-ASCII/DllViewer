#pragma once

#include "stdafx.h"
#include "dllviewer.h"
#include "applicationcontroller.hpp"
#include <memory>
#include <QtWidgets/QApplication>

namespace DllViewerApp
{
	class Application : public QObject
	{
		Q_OBJECT

	public:
		Application(int argc, char *argv[]);

	private slots:
		void slot_TerminateProcess(DWORD pid);

	private:
		QApplication m_app;
		std::unique_ptr<ApplicationController> m_appController;
		std::unique_ptr<DllViewer> m_mainFrame;
	};
}