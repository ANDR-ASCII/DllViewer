#pragma once

#include "models/processsnapshotmodel.hpp"
#include "models/modulesnapshotmodel.hpp"
#include <QtWidgets/QMainWindow>
#include "ui_dllviewer.h"

namespace DllViewerApp
{
	class DllViewer : public QMainWindow
	{
		Q_OBJECT

	public:
		DllViewer(QWidget *parent = 0, bool seDebugPrivilegeEnabled = false);

	Q_SIGNALS:
		void signal_TerminateButtonClicked(DWORD);

	private Q_SLOTS:
		void slot_ProcessViewSelectionChanged(QItemSelection const& selected, QItemSelection const& deselected);
		void slot_SearchLineEditRetPressed();
		void slot_TerminateButtonClicked();
		void slot_ShowErrorMessageBox(QString text);

	private:
		Ui::DllViewerClass ui;
		ProcessSnapshotModel* m_processSnapModel;
		ModuleSnapshotModel*  m_moduleSnapModel;
	};
}
