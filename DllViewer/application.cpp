#include "stdafx.h"
#include "application.hpp"
#include "common/common.hpp"
#include "common/servicelocator.hpp"
#include "applicationbaseexceptions.hpp"
#include <cassert>
#include <QObject>

namespace DllViewerApp
{
	using namespace Common;

	Application::Application(int argc, char *argv[])
		: m_app{ argc, argv }
		, m_appController(new ApplicationController)
	{
		m_appController->setSeDebugName(true);

		if (m_appController->seDebugName() == false)
		{
			showMessageBox("Advice", "This program should be started behalf administrator");
		}

		try
		{
			m_mainFrame.reset(new DllViewer);
			
			verifySignalSlotConnection(
				connect(m_mainFrame.get(), SIGNAL(signal_TerminateButtonClicked(DWORD)), this, SLOT(slot_TerminateProcess(DWORD))),
				WHERE_CRASH_INFO
			);

			m_mainFrame->show();

			m_app.exec();
		}
		catch (AppExceptions::ApplicationRunTimeException const& e)
		{
			Common::showMessageBox("Exception", e.what());
		}
	}

	void Application::slot_TerminateProcess(DWORD pid)
	{
		m_appController->terminateProcess(pid);
	}

}