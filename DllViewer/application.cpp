#include "afx.h"
#include "stdafx.h"
#include "application.hpp"
#include "common/common.hpp"
#include "common/servicelocator.hpp"
#include <cassert>
#include <QObject>

namespace DllViewerApp
{
	using namespace Common;

	Application::Application(int argc, char *argv[])
		: m_app(argc, argv)
		, m_appController(new ApplicationController(this))
	{
		m_appController->setSeDebugName(true);

		if (m_appController->seDebugName() == false)
		{
			showMessageBox("Advice", "This program should be started behalf administrator");
		}

		m_mainFrame.reset(new DllViewer);

		VERIFY(connect(m_mainFrame.get(), SIGNAL(signal_TerminateButtonClicked(DWORD)), this, SLOT(slot_TerminateProcess(DWORD))));

		m_mainFrame->show();
		m_app.exec();
	}

	void Application::slot_TerminateProcess(DWORD pid)
	{
		m_appController->terminateProcess(pid);
	}

}