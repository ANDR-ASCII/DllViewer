#pragma once

#include <stdexcept>
#include <string>
#include <memory>
#include <cctype>
#include <QObject>
#include <QString>

#define CPP_11_MACRO_VALUE 201103L
#define CPP_14_MACRO_VALUE 201402L

#ifndef NDEBUG
#define VERIFY(F) assert(F)
#else
#define VERIFY(F) F
#endif

namespace Common
{
	bool isOnlyDigits(QString const& str);
	void showMessageBox(QString const& title, QString const& text);
}