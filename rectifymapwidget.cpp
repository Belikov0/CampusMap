#include "rectifymapwidget.h"
#include "ui_rectifymapwidget.h"

RectifyMapWidget::RectifyMapWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RectifyMapWidget)
{
    ui->setupUi(this);
}

RectifyMapWidget::RectifyMapWidget(CampusMap *_map, QWidget *parent)
{

    RectifyMapWidget();
    setMap(_map);
}

RectifyMapWidget::~RectifyMapWidget()
{
    delete ui;
}
