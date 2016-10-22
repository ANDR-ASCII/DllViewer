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
		DllViewer(QWidget *parent = 0);

	signals:
		void signal_TerminateButtonClicked(DWORD);
		void signal_StartProcessButtonClicked();

	private slots:
		void slot_SearchLineEditRetPressed();
		void slot_TerminateButtonClicked();

	private:
		Ui::DllViewerClass ui;
		ProcessSnapshotModel* m_processSnapModel;
		ModuleSnapshotModel*  m_moduleSnapModel;
	};
}
