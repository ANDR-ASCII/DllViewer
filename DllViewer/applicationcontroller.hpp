#pragma once

#include <windows.h>

namespace DllViewerApp
{
	class ApplicationController
	{
	public:
		ApplicationController();

		void setSeDebugName(bool flag);
		bool seDebugName() const;

		void terminateProcess(DWORD pid) const;

	private:
		bool m_seDebugName;
	};
}