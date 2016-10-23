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
	{
		ServiceLocator* serviceLocator = ServiceLocator::instance();
		serviceLocator->addService<ApplicationController>(new ApplicationController);

		ApplicationController* appController = serviceLocator->service<ApplicationController>();

		appController->setSeDebugPrivilege(true);

		m_mainFrame.reset(new DllViewer(nullptr, appController->seDebugPrivilege()));

		VERIFY(connect(m_mainFrame.get(), SIGNAL(signal_TerminateButtonClicked(DWORD)), this, SLOT(slot_TerminateProcess(DWORD))));

		m_mainFrame->show();
		m_app.exec();
	}

	void Application::slot_TerminateProcess(DWORD pid)
	{
		ServiceLocator* serviceLocator = ServiceLocator::instance();
		ApplicationController* appController = serviceLocator->service<ApplicationController>();

		appController->terminateProcess(pid);
	}

}
