#include "rectifymapwidget.h"
#include "ui_rectifymapwidget.h"

RectifyMapWidget::RectifyMapWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RectifyMapWidget)
{
    ui->setupUi(this);
}

RectifyMapWidget::~RectifyMapWidget()
{
    delete ui;
}
