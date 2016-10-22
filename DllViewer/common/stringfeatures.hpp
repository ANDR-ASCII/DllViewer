#pragma once

#include <algorithm>
#include <locale>
#include <string>
#include <cwctype>
#include <QString>

namespace Common
{
	class StringFeatures
	{
	public:
		static std::string wcharToString(wchar_t const* wideString)
		{
			char defaultCharacter = 0;
			std::size_t sz = std::wcslen(wideString);
			std::unique_ptr<char[]> string{ new char[sz + 1] };

			::WideCharToMultiByte(CP_ACP, 0, wideString, -1, string.get(), (int)sz + 1, &defaultCharacter, NULL);

			std::string result = string.get();
			return result;
		}

		static QString wcharToQString(wchar_t const* wideString)
		{
			char defaultCharacter = 0;
			std::size_t sz = std::wcslen(wideString);
			std::unique_ptr<char[]> string{ new char[sz + 1] };

			::WideCharToMultiByte(CP_ACP, 0, wideString, -1, string.get(), (int)sz + 1, &defaultCharacter, NULL);

			QString result = string.get();
			return result;
		}

		template<typename T>
		static T toLower(T const& str)
		{
			ReturnTypeTraits<T>::return_type result = str;
			ReturnTypeTraits<T>::ToLower transformFunction;

			transformFunction(result);

			return result;
		}

	private:

		template<typename T>
		struct ReturnTypeTraits;

		template<>
		struct ReturnTypeTraits<std::string>
		{
			using return_type = std::string;

			struct ToLower
			{
				void operator()(std::string& str) const
				{
					std::transform(str.begin(), str.end(), str.begin(), [](char& ch) {return std::tolower(ch); });
				}
			};
		};

		template<>
		struct ReturnTypeTraits<std::wstring>
		{
			using return_type = std::wstring;
			
			struct ToLower
			{
				void operator()(std::wstring& str) const
				{
					std::transform(str.begin(), str.end(), str.begin(), [](wchar_t& ch) {return std::towlower(ch); });
				}
			};
		};

		template<>
		struct ReturnTypeTraits<QString>
		{
			using return_type = QString;
			
			struct ToLower
			{
				void operator()(QString& str) const
				{
					str.toLower();
				}
			};
		};

	};
}