#include "searchbuildingwidget.h"
#include "ui_searchbuildingwidget.h"

SearchBuildingWidget::SearchBuildingWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SearchBuildingWidget)
{
    ui->setupUi(this);
}

SearchBuildingWidget::~SearchBuildingWidget()
{
    delete ui;
}

void SearchBuildingWidget::on_searchBuldingLineEdit_textChanged(const QString &arg1)
{
//    QString s = ui->searchBuldingLineEdit;
}

