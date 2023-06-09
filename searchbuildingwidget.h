#ifndef SEARCHBUILDINGWIDGET_H
#define SEARCHBUILDINGWIDGET_H

#include <QWidget>
#include <string>
#include "mapdata.h"
using namespace std;

namespace Ui {
class SearchBuildingWidget;
}

class SearchBuildingWidget : public QWidget, public MapData
{
    Q_OBJECT
public:
    explicit SearchBuildingWidget(QWidget *parent = nullptr);
    SearchBuildingWidget(CampusMap* _map, QWidget *parent = nullptr);
    ~SearchBuildingWidget();

private slots:
    void on_searchBuldingLineEdit_textChanged(const QString &arg1);

private:
    Ui::SearchBuildingWidget *ui;
};

#endif // SEARCHBUILDINGWIDGET_H
