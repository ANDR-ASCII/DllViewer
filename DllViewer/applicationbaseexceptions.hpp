#pragma once

#include <stdexcept>

namespace AppExceptions
{
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