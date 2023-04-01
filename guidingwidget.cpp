#include "guidingwidget.h"
#include "ui_guidingwidget.h"

GuidingWidget::GuidingWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GuidingWidget)
{
    ui->setupUi(this);
}

GuidingWidget::~GuidingWidget()
{
    delete ui;
}
