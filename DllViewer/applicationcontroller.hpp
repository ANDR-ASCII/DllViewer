#pragma once

#include "applicationbaseexceptions.hpp"
#include <windows.h>

namespace DllViewerApp
{
	class ApplicationControllerException : public AppExceptions::ApplicationRunTimeException
	{};

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