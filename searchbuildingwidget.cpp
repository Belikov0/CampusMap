#include "searchbuildingwidget.h"
#include "ui_searchbuildingwidget.h"

SearchBuildingWidget::SearchBuildingWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SearchBuildingWidget)
{
    ui->setupUi(this);
}

SearchBuildingWidget::SearchBuildingWidget(CampusMap *_map, QWidget *parent):
    QWidget(parent),
    ui(new Ui::SearchBuildingWidget)
{

    ui->setupUi(this);
    this->setWindowTitle("查询建筑");
    setMap(_map);
}

SearchBuildingWidget::~SearchBuildingWidget()
{
    delete ui;
}

void SearchBuildingWidget::on_searchBuldingLineEdit_textChanged(const QString &arg1)
{
    string s = ui->searchBuldingLineEdit->text().toStdString();
    vector<string> res;

    //根据下拉框不同的条件搜索建筑
    switch (ui->conditionComboBox->currentIndex()){
        case 0:
            res = getMap()->findBuildingByBuildingName(s);
        break;
        case 1:
            res = getMap()->findBuildingByfacility(s);
        break;
    }
    if (res.empty()){
        ui->innerMessageTextBrowser->setText("");
        ui->outerMessageTextBrowser->setText("");
    }
    ui->innerMessageTextBrowser->setText(QString::fromStdString(res[0]));
    ui->outerMessageTextBrowser->setText(QString::fromStdString(res[1]));

}

