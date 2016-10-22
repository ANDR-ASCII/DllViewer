#pragma once

#include <stdexcept>
#include <limits>
#include <cassert>
#include <QAbstractTableModel>

class SnapshotException : public std::runtime_error
{
public:
	SnapshotException(std::string const& errorMessage)
		: std::runtime_error{ errorMessage }
	{}

	SnapshotException(char const* errorMessage)
		: std::runtime_error{ errorMessage }
	{}
};

class AbstractSnapshotModel : public QAbstractTableModel
{
	Q_OBJECT

public:
	AbstractSnapshotModel(QObject * parent = Q_NULLPTR)
		: QAbstractTableModel{ parent }
	{}

	~AbstractSnapshotModel() = default;

	// QAbstractTableModel implementation
	virtual QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override
	{
		if (orientation == Qt::Horizontal && section >= m_HorizontalHeaderData.size() ||
			orientation == Qt::Vertical && section >= m_VecticalHeaderData.size())
		{
			return QString{};
		}

		auto const& container = orientation == Qt::Vertical ? m_VecticalHeaderData : m_HorizontalHeaderData;

		if (role == Qt::DisplayRole)
		{
			return container[section];
		}

		return QVariant{};
	}

	// interface

	// updates the containing snapshot
	virtual void update(DWORD = 0) = 0;

protected:
	void setHorizontalHeaderLabels(QStringList const& headerLabels)
	{
		m_HorizontalHeaderData = headerLabels;
		emit headerDataChanged(Qt::Horizontal, 0, headerLabels.size());
	}

	void setVerticalHeaderLabels(QStringList const& headerLabels)
	{
		m_VecticalHeaderData = headerLabels;
		emit headerDataChanged(Qt::Vertical, 0, headerLabels.size());
	}

	int headerLabelsSize(int role) const
	{
		assert(role == Qt::Vertical || role == Qt::Horizontal);

		if (role == Qt::Horizontal)
		{
			return m_HorizontalHeaderData.size();
		}

		return m_VecticalHeaderData.size();
	}

	// throwing an exception if "condition" evaluates as false
	void check(bool condition, char const* errorMessage) const
	{
		if (!condition)
		{
			throw SnapshotException{ errorMessage };
		}
	}

private:
	QStringList m_HorizontalHeaderData;
	QStringList m_VecticalHeaderData;
};