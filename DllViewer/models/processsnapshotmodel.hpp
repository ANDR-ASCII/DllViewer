#pragma once

#include "abstractsnapshotmodel.hpp"
#include "common/common.hpp"
#include <string>
#include <vector>
#include <memory>
#include <stdexcept>
#include <QTimer>
#include <windows.h>
#include <tlhelp32.h>

namespace DllViewerApp
{

	class ProcessSnapshotModel : public AbstractSnapshotModel
	{
		Q_OBJECT

	private:
		struct ProcessInfo
		{
			std::wstring processName;
			DWORD processID;
			DWORD parentProcessID;
			DWORD countThreads;
			DWORD priorityClass;
		};

	public:
		enum SearchType
		{
			ByPID
			, ByName
		};

		enum FieldType
		{
			Name
			, PID
			, ParentPID
			, CountThreads
			, PriorityClass
		};

		ProcessSnapshotModel(QObject * parent = Q_NULLPTR);
		~ProcessSnapshotModel() = default;

		void update(DWORD = 0);

		QModelIndex search(QString const& str, SearchType type);
		bool existsItemOf(QModelIndex const& index) const;
		QVariant getValue(QModelIndex const& index) const;
		QVariant getValue(int row, int column) const;

		// QAbstractItemModel implementation
		virtual int rowCount(const QModelIndex &parent = QModelIndex{}) const override;
		virtual int columnCount(const QModelIndex &parent = QModelIndex{}) const override;
		virtual QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

	private slots:
		void timedUpdater();

	private:
		void clear()
		{
			m_storage.clear();
		}

		QModelIndex searchByPID(int pid);
		QModelIndex searchByName(QString const& str);

		std::pair<bool, ProcessInfo> createItem(PPROCESSENTRY32W pEntry) const;
		QVariant retrievePriorityClass(DWORD priorityClass) const;

	private:
		std::vector<ProcessInfo> m_storage;
		QTimer* m_timer;
	};

}