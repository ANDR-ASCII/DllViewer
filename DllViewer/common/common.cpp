#include "stdafx.h"
#include "common.hpp"
#include <memory>
#include <windows.h>

std::string Common::wcharToString(wchar_t const* wideString)
{
	char defaultCharacter = 0;
	std::size_t sz = std::wcslen(wideString);
	std::unique_ptr<char[]> string{ new char[sz + 1] };

	::WideCharToMultiByte(CP_ACP, 0, wideString, -1, string.get(), sz + 1, &defaultCharacter, NULL);

	std::string result = string.get();
	return result;
}

QString Common::wcharToQString(wchar_t const* wideString)
{
	char defaultCharacter = 0;
	std::size_t sz = std::wcslen(wideString);
	std::unique_ptr<char[]> string{ new char[sz + 1] };

	::WideCharToMultiByte(CP_ACP, 0, wideString, -1, string.get(), sz + 1, &defaultCharacter, NULL);

	QString result = string.get();
	return result;
}