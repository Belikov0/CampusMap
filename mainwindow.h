#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <string>
#include "matgraph.h"
#include "vertextype.h"
#include "searchbuildingwidget.h"
#include "searchroutewidget.h"
#include "rectifymapwidget.h"
#include "guidingwidget.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_searchBuildingPushButton_clicked();

    void on_rectifyMapPushButton_clicked();

    void on_searchRoutePushButton_clicked();

    void on_guidingPushButton_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
