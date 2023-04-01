#include "searchbuildingwidget.h"
#include "ui_searchbuildingwidget.h"

SearchBuildingWidget::SearchBuildingWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SearchBuildingWidget)
{
    ui->setupUi(this);
}

SearchBuildingWidget::SearchBuildingWidget(CampusMap *_map, QWidget *parent)
{
    SearchBuildingWidget();
    setMap(_map);
    QStringList str;

}

SearchBuildingWidget::~SearchBuildingWidget()
{
    delete ui;
}

void SearchBuildingWidget::on_searchBuldingLineEdit_textChanged(const QString &arg1)
{
    string s = ui->searchBuldingLineEdit->text().toStdString();

}

