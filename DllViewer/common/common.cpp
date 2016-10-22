#include "stdafx.h"
#include "common.hpp"
#include "applicationbaseexceptions.hpp"
#include <memory>
#include <cstring>
#include <windows.h>

namespace Common
{
	bool isOnlyDigits(QString const& str)
	{
		for (std::size_t i = 0, sz = str.size(); i < sz; ++i)
		{
			if (!std::isdigit(str.toStdString()[i]))
			{
				return false;
			}
		}

		return true;
	}

	void showMessageBox(QString const& title, QString const& text)
	{
		QMessageBox temp;
		temp.setWindowTitle(title);
		temp.setText(text);
		temp.exec();
	}

}