#ifndef RECTIFYMAPWIDGET_H
#define RECTIFYMAPWIDGET_H

#include <QWidget>
#include <string>
#include "mapdata.h"
using namespace std;

namespace Ui {
class RectifyMapWidget;
}

class RectifyMapWidget : public QWidget, public MapData
{
    Q_OBJECT

public:
    explicit RectifyMapWidget(QWidget *parent = nullptr);
    RectifyMapWidget(CampusMap* _map, QWidget *parent = nullptr);

    ~RectifyMapWidget();

private:
    Ui::RectifyMapWidget *ui;
};

#endif // RECTIFYMAPWIDGET_H
