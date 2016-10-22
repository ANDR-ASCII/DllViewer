#pragma once

#include <stdexcept>
#include <string>
#include <memory>
#include <cctype>
#include <QObject>
#include <QString>

#define CPP_11_MACRO_VALUE 201103L
#define CPP_14_MACRO_VALUE 201402L

#define WHERE_CRASH_INFO \
	__LINE__, std::string{ __FUNCTION__ }

namespace Common
{
	std::string wcharToString(wchar_t const* wideString);
	QString wcharToQString(wchar_t const* wideString);
	void verifySignalSlotConnection(QMetaObject::Connection connectionObject, int lineNumber, std::string const& fromCall = "");
	bool isOnlyDigits(QString const& str);
	void showMessageBox(QString const& title, QString const& text);

	class ApplicationRunTimeException : public std::runtime_error
	{
	public:
		ApplicationRunTimeException(std::string const& errorMessage)
			: std::runtime_error(errorMessage)
		{}

		ApplicationRunTimeException(char const* errorMessage)
			: std::runtime_error(errorMessage)
		{}
	};

	class SignalSlotBadConnection : public ApplicationRunTimeException
	{
	public:
		SignalSlotBadConnection(std::string const& errorMessage)
			: ApplicationRunTimeException(errorMessage)
		{}

		SignalSlotBadConnection(char const* errorMessage)
			: ApplicationRunTimeException(errorMessage)
		{}
	};
}