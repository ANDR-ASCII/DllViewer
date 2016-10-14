#include <stdafx.h>
#include "modulesnapshotmodel.hpp"
#include <cwchar>
#include <tchar.h>

namespace DllViewerApp
{

	ModuleSnapshotModel::ModuleSnapshotModel(QObject * parent, DWORD pid)
		: AbstractSnapshotModel(parent)
		, m_timer(::new QTimer(this))
		, m_pid(pid)
	{
		QStringList headerLabels;

		headerLabels
			<< "Module name"
			<< "Path"
			<< "PID"
			<< "Module ID"
			<< "Global usage counter"
			<< "Module usage counter"
			<< "Base address"
			<< "Base size";

		setHorizontalHeaderLabels(headerLabels);
		update(m_pid);

		Common::verifySignalSlotConnection(
			connect(m_timer.get(), SIGNAL(timeout()), this, SLOT(timedUpdater())),
			WHERE_CRASH_INFO
		);

		m_timer->start(300);
	}

	int ModuleSnapshotModel::rowCount(const QModelIndex& parent) const
	{
		return m_storage.size();
	}

	int ModuleSnapshotModel::columnCount(const QModelIndex& parent) const
	{
		return headerLabelsSize(Qt::Horizontal);
	}

	QVariant ModuleSnapshotModel::data(const QModelIndex& index, int role) const
	{
		if (!index.isValid() || !existsItemOf(index))
		{
			return QVariant{};
		}

		if (role == Qt::DisplayRole)
		{
			return getValue(index);
		}

		return QVariant{};
	}

	void ModuleSnapshotModel::update(DWORD pid)
	{
		HANDLE hSnapshot = ::CreateToolhelp32Snapshot(TH32CS_SNAPMODULE, pid);

		check(hSnapshot != INVALID_HANDLE_VALUE,
			"You don't have permissions for open this process");

		check(GetLastError() == ERROR_ACCESS_DENIED, 
			"");

		m_pid = pid;

		clear();

		MODULEENTRY32W meEntry32;
		meEntry32.dwSize = sizeof(meEntry32);

		check(::Module32First(hSnapshot, &meEntry32) != FALSE,
			"Cannot retrieve information about some module");

		do
		{
			m_storage.push_back(createItem(&meEntry32));

		} while (::Module32Next(hSnapshot, &meEntry32));

		::CloseHandle(hSnapshot);
	}

	void ModuleSnapshotModel::timedUpdater()
	{
		update(m_pid);
	}

	QVariant ModuleSnapshotModel::getValue(QModelIndex const & index) const
	{
		switch (index.column())
		{
		case FieldType::Name:
			return Common::wcharToQString(m_storage[index.row()].moduleName.c_str());

		case FieldType::Path:
			return Common::wcharToQString(m_storage[index.row()].path.c_str());

		case FieldType::PID:
			return static_cast<int>(m_storage[index.row()].processID);

		case FieldType::ModuleID:
			return static_cast<int>(m_storage[index.row()].moduleID);

		case FieldType::GlobalUsageCounter:
			return static_cast<int>(m_storage[index.row()].globalUsageCounter);

		case FieldType::ModuleUsageCounter:
			return static_cast<int>(m_storage[index.row()].moduleUsageCounter);

		case FieldType::ModuleBaseAddress:
		{
			wchar_t addressString[256];
			std::swprintf(addressString, L"%p", m_storage[index.row()].moduleBaseAddress);
			return Common::wcharToQString(addressString);
		}

		case FieldType::ModuleBaseSize:
			return static_cast<int>(m_storage[index.row()].moduleBaseSize);
		}

		return QVariant{};
	}

	QVariant ModuleSnapshotModel::getValue(int row, int column) const
	{
		return getValue(QAbstractItemModel::createIndex(row, column, nullptr));
	}

	ModuleSnapshotModel::ModuleInfo ModuleSnapshotModel::createItem(PMODULEENTRY32W pEntry) const
	{
		return ModuleInfo
		{
			  pEntry->szModule
			, pEntry->szExePath
			, pEntry->th32ProcessID
			, pEntry->th32ModuleID
			, pEntry->GlblcntUsage
			, pEntry->ProccntUsage
			, pEntry->modBaseAddr
			, pEntry->modBaseSize
			, pEntry->hModule
		};
	}

	bool ModuleSnapshotModel::existsItemOf(QModelIndex const& index) const
	{
		if (rowCount() == 0 ||
			index.row() >= rowCount() ||
			index.column() >= headerLabelsSize(Qt::Horizontal))
		{
			return false;
		}

		return true;
	}

}