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

	class ModuleSnapshotModel : public AbstractSnapshotModel
	{
		Q_OBJECT

	private:
		struct ModuleInfo
		{
			std::wstring moduleName;
			std::wstring path;
			DWORD processID;                // owning process
			DWORD moduleID;                 // This module
			DWORD globalUsageCounter;       // Global usage count on the module
			DWORD moduleUsageCounter;       // Module usage count in th32ProcessID's context
			PBYTE moduleBaseAddress;        // Base address of module in th32ProcessID's context
			DWORD moduleBaseSize;           // Size in bytes of module starting at modBaseAddr
			HMODULE hModule;                // The hModule of this module in th32ProcessID's context
		};

	public:

		enum FieldType
		{
			  Name
			, Path
			, ModuleBaseAddress
			, ModuleBaseSize
		};

		ModuleSnapshotModel(QObject * parent = Q_NULLPTR, DWORD pid = 0);
		~ModuleSnapshotModel() = default;

		bool existsItemOf(QModelIndex const& index) const;
		QVariant getValue(QModelIndex const& index) const;
		QVariant getValue(int row, int column) const;

		// QAbstractTableModel implementation
		virtual int rowCount(const QModelIndex &parent = QModelIndex{}) const override;
		virtual int columnCount(const QModelIndex &parent = QModelIndex{}) const override;
		virtual QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

		// AbstractSnapshotModel implementation

		// updates the containing snapshot
		virtual void update(DWORD pid = 0) override;

	signals:
		void signal_OnError(QString str);

	private slots:
		void slot_TimedUpdater();

	private:

		void clear()
		{
			m_storage.clear();
		}

		ModuleInfo createItem(PMODULEENTRY32W pEntry) const;

	private:
		std::vector<ModuleInfo> m_storage;
		QTimer* m_timer;
		DWORD m_pid;
	};

}