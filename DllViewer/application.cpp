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
				connect(m_mainFrame.get(), SIGNAL(terminateButtonClicked()), this, SLOT(slot_TerminateProcess())),
				WHERE_CRASH_INFO
			);

			m_mainFrame->show();
		}
		catch (std::exception const& e)
		{
			Common::showMessageBox("Exception", e.what());
		}
	}

	Application::~Application()
	{
		m_app.exec();
	}

	void Application::slot_TerminateProcess(DWORD pid)
	{
		m_appController->terminateProcess(pid);
	}

}