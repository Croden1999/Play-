#pragma once

#include <QAbstractTableModel>

class CQtGenericTableModel : public QAbstractTableModel
{
	Q_OBJECT
public:
	CQtGenericTableModel(QObject* parent, std::vector<std::string>);
	~CQtGenericTableModel();

	int rowCount(const QModelIndex& parent = QModelIndex()) const Q_DECL_OVERRIDE;
	int columnCount(const QModelIndex& parent = QModelIndex()) const Q_DECL_OVERRIDE;
	QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const Q_DECL_OVERRIDE;
	void DoubleClicked(const QModelIndex& index, QWidget* parent = nullptr);

	bool addItem(std::vector<std::string>);
	void clear();

protected:
	QVariant headerData(int section, Qt::Orientation orientation, int role) const Q_DECL_OVERRIDE;

private:
	std::vector<std::vector<std::string>> m_data;
	QVariantList m_headers;
};
