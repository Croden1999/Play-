#include "QtGenericTableModel.h"

CQtGenericTableModel::CQtGenericTableModel(QObject* parent, std::vector<std::string> headers)
    : QAbstractTableModel(parent)
{
	for(int i = 0; i < headers.size(); ++i)
		m_headers.insert(i, QVariant(headers[i].c_str()));
}

CQtGenericTableModel::~CQtGenericTableModel()
{
}

int CQtGenericTableModel::rowCount(const QModelIndex& /*parent*/) const
{
	return m_data.size();
}

int CQtGenericTableModel::columnCount(const QModelIndex& /*parent*/) const
{
	return m_headers.size();
}

QVariant CQtGenericTableModel::data(const QModelIndex& index, int role) const
{
	if(role == Qt::DisplayRole)
	{
		auto data = m_data.at(index.row());
		return QVariant(data.at(index.column()).c_str());
	}
	return QVariant();
}

QVariant CQtGenericTableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
	if(orientation == Qt::Horizontal)
	{
		if(role == Qt::DisplayRole)
		{
			if(section < m_headers.size())
			{
				return m_headers.at(section);
			}
		}
	}

	return QAbstractTableModel::headerData(section, orientation, role);
}

void CQtGenericTableModel::DoubleClicked(const QModelIndex& index, QWidget* parent)
{
	// TODO signal
}

bool CQtGenericTableModel::addItem(std::vector<std::string> data)
{
	if(data.size() != m_headers.size())
		return false;

	emit QAbstractTableModel::beginInsertRows(QModelIndex(), rowCount(), rowCount());
	m_data.push_back(data);
	emit QAbstractTableModel::endInsertRows();
	return true;
}

void CQtGenericTableModel::clear()
{
	emit QAbstractTableModel::beginResetModel();
	m_data.clear();
	emit QAbstractTableModel::endResetModel();
}