#pragma once

#include "stdafx.h"
#include "dllviewer.h"
#include <memory>
#include <QtWidgets/QApplication>

namespace DllViewerApp
{
	class Application
	{
	public:
		Application(int argc, char *argv[]);
		~Application();

	private:
		bool setSeDebugNamePrivilege(bool flag);

	private:
		QApplication m_app;

		std::unique_ptr<DllViewer> m_mainFrame;

		bool m_seDebugNameTurnedOn;
	};
}