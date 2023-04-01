#ifndef GUIDINGWIDGET_H
#define GUIDINGWIDGET_H

#include <QWidget>
#include "mapdata.h"

namespace Ui {
class GuidingWidget;
}

class GuidingWidget : public QWidget, public MapData
{
    Q_OBJECT

public:
    explicit GuidingWidget(QWidget *parent = nullptr);
    GuidingWidget(CampusMap* _map, QWidget *parent = nullptr);
    ~GuidingWidget();

private:
    Ui::GuidingWidget *ui;
};

#endif // GUIDINGWIDGET_H
