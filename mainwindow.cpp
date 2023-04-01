#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_searchBuildingPushButton_clicked()
{
    SearchBuildingWidget* s = new SearchBuildingWidget();
    s->show();
}


void MainWindow::on_rectifyMapPushButton_clicked()
{
    RectifyMapWidget* r = new RectifyMapWidget();
    r->show();
}




void MainWindow::on_searchRoutePushButton_clicked()
{
    SearchRouteWidget* s = new SearchRouteWidget();
    s->show();
}




void MainWindow::on_guidingPushButton_clicked()
{
    GuidingWidget* g = new GuidingWidget();
    g->show();
}

