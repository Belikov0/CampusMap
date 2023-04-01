#include "guidingwidget.h"
#include "ui_guidingwidget.h"

GuidingWidget::GuidingWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GuidingWidget)
{
    ui->setupUi(this);
}

GuidingWidget::GuidingWidget(CampusMap *_map, QWidget *parent)
{
    GuidingWidget();
    setMap(_map);
}

GuidingWidget::~GuidingWidget()
{
    delete ui;
}
