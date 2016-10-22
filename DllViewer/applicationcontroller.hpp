#pragma once

#include <QObject>
#include <windows.h>

namespace DllViewerApp
{
	class ApplicationController : public QObject
	{
		Q_OBJECT

	public:
		ApplicationController(QObject* parent = nullptr);

		void setSeDebugName(bool flag);
		bool seDebugName() const;

		void terminateProcess(DWORD pid) const;

	private:
		bool m_seDebugName;
	};
}