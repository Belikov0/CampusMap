#include "searchroutewidget.h"
#include "ui_searchroutewidget.h"

SearchRouteWidget::SearchRouteWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SearchRouteWidget)
{
    ui->setupUi(this);
}

SearchRouteWidget::~SearchRouteWidget()
{
    delete ui;
}
