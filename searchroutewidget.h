#ifndef SEARCHROUTEWIDGET_H
#define SEARCHROUTEWIDGET_H

#include <QWidget>
#include <string>
#include "mapdata.h"
using namespace std;

namespace Ui {
class SearchRouteWidget;
}

class SearchRouteWidget : public QWidget, public MapData
{
    Q_OBJECT
public:
    explicit SearchRouteWidget(QWidget *parent = nullptr);
    SearchRouteWidget(CampusMap* _map, QWidget *parent = nullptr);
    ~SearchRouteWidget();

private:
    Ui::SearchRouteWidget *ui;
};

#endif // SEARCHROUTEWIDGET_H
