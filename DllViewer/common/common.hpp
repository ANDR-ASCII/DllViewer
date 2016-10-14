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

	class ApplicationRunTimeException : public std::runtime_error
	{
	public:
		ApplicationRunTimeException(std::string const& errorMessage)
			: std::runtime_error(errorMessage)
		{}

#if __cplusplus >= CPP_11_MACRO_VALUE

		ApplicationRunTimeException(char const* errorMessage)
			: std::runtime_error(errorMessage)
		{}

#endif

	};

	class SignalSlotBadConnection : public ApplicationRunTimeException
	{
	public:
		SignalSlotBadConnection(std::string const& errorMessage)
			: ApplicationRunTimeException(errorMessage)
		{}

#if __cplusplus >= CPP_11_MACRO_VALUE

		SignalSlotBadConnection(char const* errorMessage)
			: ApplicationRunTimeException(errorMessage)
		{}

#endif

	};

	inline void verifySignalSlotConnection(QMetaObject::Connection connectionObject, int lineNumber, std::string const& fromCall = "")
	{
		if (!connectionObject)
		{
			std::string resultFromCall;

			if (fromCall.size())
			{
				resultFromCall = "From: " + fromCall + "\n";
				resultFromCall += "Line: " + std::to_string(lineNumber);
			}

			throw SignalSlotBadConnection{ std::string{ "Bad signal/slot connection.\n\n" } + resultFromCall };
		}
	}

	inline bool isOnlyDigits(QString const& str)
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

}