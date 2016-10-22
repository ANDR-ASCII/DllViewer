#include "stdafx.h"
#include "dllviewer.h"
#include "common/servicelocator.hpp"

namespace DllViewerApp
{
	DllViewer::DllViewer(QWidget *parent)
		: QMainWindow(parent)
		, m_processSnapModel(new ProcessSnapshotModel)
		, m_moduleSnapModel(new ModuleSnapshotModel)
	{
		ui.setupUi(this);

		Common::verifySignalSlotConnection(
			connect(ui.searchLineEdit, SIGNAL(returnPressed()), this, SIGNAL(slot_SearchLineEditRetPressed())),
			WHERE_CRASH_INFO
		);

		Common::verifySignalSlotConnection(
			connect(ui.terminateButton, SIGNAL(clicked()), this, SLOT(slot_TerminateButtonClicked())),
			WHERE_CRASH_INFO
		);

		Common::verifySignalSlotConnection(
			connect(ui.startProcessButton, SIGNAL(clicked()), this, SIGNAL(signal_StartProcessButtonClicked())),
			WHERE_CRASH_INFO
		);

		ui.processView->setAlternatingRowColors(true);
		ui.processView->setModel(m_processSnapModel);

		ui.dllsView->setAlternatingRowColors(true);
		ui.dllsView->setModel(m_moduleSnapModel);
	}

	void DllViewer::slot_SearchLineEditRetPressed()
	{

	}

	void DllViewer::slot_TerminateButtonClicked()
	{

	}

}