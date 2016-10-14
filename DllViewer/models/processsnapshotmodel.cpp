﻿#include <stdafx.h>
#include "processsnapshotmodel.hpp"

namespace DllViewerApp
{

	ProcessSnapshotModel::ProcessSnapshotModel(QObject * parent)
		: AbstractSnapshotModel{ parent }
		, m_timer{ new QTimer{ this } }
	{
		QStringList headerLabels;

		headerLabels
			<< "Process name"
			<< "PID"
			<< "Parent PID"
			<< "Threads"
			<< "Priority base";

		setHorizontalHeaderLabels(headerLabels);
		update();

		Common::verifySignalSlotConnection(
			connect(m_timer.get(), SIGNAL(timeout()), this, SLOT(timedUpdater())),
			WHERE_CRASH_INFO
		);

		m_timer->start(300);
	}

	QModelIndex ProcessSnapshotModel::search(QString const& str, SearchType type)
	{
		switch (type)
		{
		case ByPID:
			return searchByPID(str.toInt());

		case ByName:
			return searchByName(str);

		default:
			return QModelIndex{};
		}
	}

	int ProcessSnapshotModel::rowCount(const QModelIndex & parent) const
	{
		return m_storage.size();
	}

	int ProcessSnapshotModel::columnCount(const QModelIndex & parent) const
	{
		return headerLabelsSize(Qt::Horizontal);
	}

	QVariant ProcessSnapshotModel::data(const QModelIndex& index, int role) const
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

	void ProcessSnapshotModel::update(DWORD pid)
	{
		Q_UNUSED(pid);

		clear();

		HANDLE hSnapshot = ::CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);

		check(hSnapshot != INVALID_HANDLE_VALUE,
			"Cannot create a processes snapshot");

		PROCESSENTRY32W peEntry32;
		peEntry32.dwSize = sizeof(peEntry32);

		check(::Process32First(hSnapshot, &peEntry32) != FALSE,
			"Cannot retrieve information about some process");

		do
		{
			std::pair<bool, ProcessInfo> pair = createItem(&peEntry32);

			if (pair.first)
			{
				m_storage.push_back(pair.second);
			}

		} while (::Process32Next(hSnapshot, &peEntry32));

		::CloseHandle(hSnapshot);
	}

	void ProcessSnapshotModel::timedUpdater()
	{
		update();
	}

	QModelIndex ProcessSnapshotModel::searchByPID(int pid)
	{
		typedef std::vector<ProcessInfo>::size_type size_type;

		for (size_type i = 0, sz = m_storage.size(); i < sz; ++i)
		{
			if (m_storage[i].processID == pid)
			{
				return QAbstractTableModel::createIndex(i, 1, this);
			}
		}

		return QModelIndex{};
	}

	QModelIndex ProcessSnapshotModel::searchByName(QString const& str)
	{
		typedef std::vector<ProcessInfo>::size_type size_type;

		for (size_type i = 0, sz = m_storage.size(); i < sz; ++i)
		{
			if (m_storage[i].processName == str.toStdWString())
			{
				return QAbstractTableModel::createIndex(i, 0, this);
			}
		}

		return QModelIndex{};
	}

	bool ProcessSnapshotModel::existsItemOf(QModelIndex const& index) const
	{
		if (rowCount() == 0 ||
			index.row() >= rowCount() ||
			index.column() >= headerLabelsSize(Qt::Horizontal))
		{
			return false;
		}

		return true;
	}

	QVariant ProcessSnapshotModel::getValue(QModelIndex const& index) const
	{
		switch (index.column())
		{
		case FieldType::Name:
			return Common::wcharToQString(m_storage[index.row()].processName.c_str());

		case FieldType::PID:
			return static_cast<int>(m_storage[index.row()].processID);

		case FieldType::ParentPID:
			return static_cast<int>(m_storage[index.row()].parentProcessID);

		case FieldType::CountThreads:
			return static_cast<int>(m_storage[index.row()].countThreads);

		case FieldType::PriorityClass:
			return retrievePriorityClass(m_storage[index.row()].priorityClass);
		}

		return QVariant{};
	}

	QVariant ProcessSnapshotModel::getValue(int row, int column) const
	{
		return getValue(QAbstractItemModel::createIndex(row, column, nullptr));
	}

	std::pair<bool, ProcessSnapshotModel::ProcessInfo> ProcessSnapshotModel::createItem(PPROCESSENTRY32W pEntry) const
	{
		ProcessInfo item
		{
			  pEntry->szExeFile
			, pEntry->th32ProcessID
			, pEntry->th32ParentProcessID
			, pEntry->cntThreads
			, 0 // invalid value
		};

		// init priority class

		HANDLE hProcess = ::OpenProcess(PROCESS_QUERY_LIMITED_INFORMATION, FALSE, pEntry->th32ProcessID);

		if (hProcess != nullptr)
		{
			item.priorityClass = ::GetPriorityClass(hProcess);
		}
		else
		{
			return std::make_pair(false, item);
		}

		::CloseHandle(hProcess);

		return std::make_pair(true, item);
	}

	QVariant ProcessSnapshotModel::retrievePriorityClass(DWORD priorityClass) const
	{
		switch (priorityClass)
		{
		case REALTIME_PRIORITY_CLASS:
			return QString{ "Real time" };

		case HIGH_PRIORITY_CLASS:
			return QString{ "High" };

		case ABOVE_NORMAL_PRIORITY_CLASS:
			return QString{ "Above normal" };

		case NORMAL_PRIORITY_CLASS:
			return QString{ "Normal" };

		case BELOW_NORMAL_PRIORITY_CLASS:
			return QString{ "Below normal" };

		case IDLE_PRIORITY_CLASS:
			return QString{ "Low" };
		}

		return QString{ "Cannot retrieve" };
	}

}