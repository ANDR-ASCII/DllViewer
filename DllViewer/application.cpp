#include "stdafx.h"
#include "application.hpp"
#include "common/common.hpp"
#include "common/servicelocator.hpp"
#include <cassert>

namespace DllViewerApp
{
	using namespace Common;

	Application::Application(int argc, char *argv[])
		: m_app(argc, argv)
		, m_seDebugNameTurnedOn(false)
	{
		m_seDebugNameTurnedOn = setSeDebugNamePrivilege(true);

		ServiceLocator* serviceLocator = ServiceLocator::instance();

		try
		{
			m_mainFrame.reset(new DllViewer);
			m_mainFrame->show();
		}
		catch (std::exception const& e)
		{

		}
	}

	Application::~Application()
	{
		if (m_seDebugNameTurnedOn)
		{
			setSeDebugNamePrivilege(false);
		}

		m_app.exec();
	}

	bool Application::setSeDebugNamePrivilege(bool flag)
	{
		HANDLE hThisProcess = ::OpenProcess(PROCESS_QUERY_LIMITED_INFORMATION, FALSE, ::GetCurrentProcessId());
		assert(hThisProcess != nullptr);

		HANDLE hThisProcessToken = 0;
		::OpenProcessToken(hThisProcess, TOKEN_ADJUST_PRIVILEGES, &hThisProcessToken);
		assert(hThisProcess != 0);

		TOKEN_PRIVILEGES tp;
		LUID luid;

		assert(::LookupPrivilegeValue(nullptr, SE_DEBUG_NAME, &luid));

		tp.PrivilegeCount = 1;
		tp.Privileges[0].Luid = luid;

		DWORD enableStatus = flag ? SE_PRIVILEGE_ENABLED : SE_PRIVILEGE_REMOVED;

		tp.Privileges[0].Attributes = enableStatus;

		assert(::AdjustTokenPrivileges(hThisProcessToken, FALSE, &tp, sizeof(TOKEN_PRIVILEGES), nullptr, nullptr));

		if (GetLastError() == ERROR_NOT_ALL_ASSIGNED)
		{
			return false;
		}

		return true;
	}

}