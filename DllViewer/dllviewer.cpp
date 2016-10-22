#include "stdafx.h"
#include "dllviewer.h"
#include "common/common.hpp"
#include "common/servicelocator.hpp"

namespace DllViewerApp
{
	DllViewer::DllViewer(QWidget *parent)
		: QMainWindow(parent)
		, m_processSnapModel(new ProcessSnapshotModel)
		, m_moduleSnapModel(new ModuleSnapshotModel)
	{
		ui.setupUi(this);

		VERIFY(connect(ui.searchLineEdit, SIGNAL(returnPressed()), this, SLOT(slot_SearchLineEditRetPressed())));
		VERIFY(connect(ui.terminateButton, SIGNAL(clicked()), this, SLOT(slot_TerminateButtonClicked())));
		VERIFY(connect(m_processSnapModel, SIGNAL(signal_OnError(QString)), this, SLOT(slot_ShowErrorMessageBox(QString))));

		ui.processView->setAlternatingRowColors(true);
		ui.processView->setModel(m_processSnapModel);

		ui.dllsView->setAlternatingRowColors(true);
		ui.dllsView->setModel(m_moduleSnapModel);
	}

	void DllViewer::slot_SearchLineEditRetPressed()
	{
		QString text = ui.searchLineEdit->text();

		if (text.isEmpty())
		{
			return;
		}

		QModelIndex index;

		if (Common::isOnlyDigits(text))
		{
			index = m_processSnapModel->search(text, ProcessSnapshotModel::ByPID);
		}
		else
		{
			index = m_processSnapModel->search(text, ProcessSnapshotModel::ByName);

			if (!index.isValid())
			{
				if (text.endsWith(".exe", Qt::CaseInsensitive))
				{
					text.left(text.size() - 4);
				}
				else
				{
					text.append(".exe");
				}

				index = m_processSnapModel->search(text, ProcessSnapshotModel::ByName);
			}
		}

		if (!index.isValid())
		{
			Common::showMessageBox("Search result", "Specified process not found");
			return;
		}

		DWORD pid = (DWORD)m_processSnapModel->getValue(index.row(), ProcessSnapshotModel::PID).toInt();
		
		QItemSelectionModel* selectionModel = ui.processView->selectionModel();

		// deselect selected
		QModelIndex selectedIndex = selectionModel->currentIndex();

		if (selectedIndex.isValid())
		{
			selectionModel->select(selectedIndex, QItemSelectionModel::Deselect);
		}

		// select new item
		QItemSelection selection(index, index);
		selectionModel->select(selection, QItemSelectionModel::Select);
		m_moduleSnapModel->update(pid);
	}

	void DllViewer::slot_TerminateButtonClicked()
	{
		QItemSelectionModel* selectionModel = ui.processView->selectionModel();

		if (selectionModel->hasSelection())
		{
			QModelIndexList modelIndexes = selectionModel->selection().indexes();
			
			auto selectedOnlyOneRow = [&modelIndexes]
			{
				int row = modelIndexes.back().row();
				for (auto beg = modelIndexes.begin(), end = modelIndexes.end() - 1; beg != end; ++beg)
				{
					if (beg->row() != row)
					{
						return false;
					}
				}

				return true;
			};

			assert(selectedOnlyOneRow());

			QModelIndex index = modelIndexes.back();
			QString pid = m_processSnapModel->getValue(index.row(), 1).toString();

			emit signal_TerminateButtonClicked((DWORD)pid.toInt());
		}
	}

	void DllViewer::slot_ShowErrorMessageBox(QString text)
	{
		Common::showMessageBox("Error", text);
	}

}