#include "stdafx.h"
#include "common.hpp"
#include "applicationbaseexceptions.hpp"
#include <memory>
#include <cstring>
#include <windows.h>

namespace Common
{
	std::string wcharToString(wchar_t const* wideString)
	{
		char defaultCharacter = 0;
		std::size_t sz = std::wcslen(wideString);
		std::unique_ptr<char[]> string{ new char[sz + 1] };

		::WideCharToMultiByte(CP_ACP, 0, wideString, -1, string.get(), (int)sz + 1, &defaultCharacter, NULL);

		std::string result = string.get();
		return result;
	}

	QString wcharToQString(wchar_t const* wideString)
	{
		char defaultCharacter = 0;
		std::size_t sz = std::wcslen(wideString);
		std::unique_ptr<char[]> string{ new char[sz + 1] };

		::WideCharToMultiByte(CP_ACP, 0, wideString, -1, string.get(), (int)sz + 1, &defaultCharacter, NULL);

		QString result = string.get();
		return result;
	}

	void verifySignalSlotConnection(QMetaObject::Connection connectionObject, int lineNumber, std::string const& fromCall)
	{
		if (!connectionObject)
		{
			std::string resultFromCall;

			if (fromCall.size())
			{
				resultFromCall = "From: " + fromCall + "\n";
				resultFromCall += "Line: " + std::to_string(lineNumber);
			}

			throw AppExceptions::SignalSlotBadConnection{ std::string{ "Bad signal/slot connection.\n\n" } +resultFromCall };
		}
	}

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