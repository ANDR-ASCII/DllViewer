#include "stdafx.h"
#include "common/common.hpp"
#include "applicationcontroller.hpp"
#include <cassert>

namespace DllViewerApp
{

	ApplicationController::ApplicationController()
		: m_seDebugName(false)
	{}

	bool ApplicationController::seDebugName() const
	{
		return m_seDebugName;
	}

	void ApplicationController::terminateProcess(DWORD pid) const
	{
		HANDLE hTerminatingProcess = ::OpenProcess(PROCESS_TERMINATE, FALSE, pid);

		if (hTerminatingProcess == NULL)
		{
			throw Common::ApplicationRunTimeException("Cannot open the specified process. Error Access denied.");
		}

		::TerminateProcess(hTerminatingProcess, 0);
	}

	void ApplicationController::setSeDebugName(bool flag)
	{
		HANDLE hThisProcess = ::OpenProcess(PROCESS_QUERY_LIMITED_INFORMATION, FALSE, ::GetCurrentProcessId());
		assert(hThisProcess != nullptr);

		HANDLE hThisProcessToken = 0;
		::OpenProcessToken(hThisProcess, TOKEN_ADJUST_PRIVILEGES, &hThisProcessToken);
		assert(hThisProcess != 0);

		TOKEN_PRIVILEGES tp;
		LUID luid;

		BOOL bResult = ::LookupPrivilegeValue(nullptr, SE_DEBUG_NAME, &luid);
		assert(bResult);

		if (!bResult)
		{
			return;
		}

		tp.PrivilegeCount = 1;
		tp.Privileges[0].Luid = luid;

		DWORD enableStatus = flag ? SE_PRIVILEGE_ENABLED : SE_PRIVILEGE_REMOVED;

		tp.Privileges[0].Attributes = enableStatus;

		assert(::AdjustTokenPrivileges(hThisProcessToken, FALSE, &tp, sizeof(TOKEN_PRIVILEGES), nullptr, nullptr));

		if (GetLastError() == ERROR_NOT_ALL_ASSIGNED)
		{
			return;
		}

		m_seDebugName = true;
	}
}