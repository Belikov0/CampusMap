#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("民大校园地图");

    string extraBuilding = "体育场";
    string buildingNames[11] = {
        "静园1号楼",
        "商业街",
        "聚雅餐厅",
        "荟闲餐厅",
        "学生活动中心",
        "综合楼",
        "日新楼",
        "明德楼",
        "致远楼",
        "崇理楼",
        "图书馆",
    };
    Building* buildings[11];
    for (int i = 0; i < 11; i++){
        buildings[i] = new Building(i, buildingNames[i]);
    }

    buildings[0]->addFacility("男生浴室")->addFacility("教师公寓");
    buildings[1]->addFacility("洗衣房")->addFacility("理发店");
    buildings[2]->addFacility("基本伙")->addFacility("活动室")->addFacility("风味餐厅");
    buildings[3]->addFacility("麻辣烫")->addFacility("烤肉饭");
    buildings[4]->addFacility("学生会办公室")->addFacility("团委办公室")->addFacility("音乐教室");
    buildings[5]->addFacility("报告大厅")->addFacility("地下停车场");
    buildings[6]->addFacility("咖啡厅")->addFacility("机房")->addFacility("阶梯教室");
    buildings[7]->addFacility("理学院办公室")->addFacility("信息工程学院办公室");
    buildings[8]->addFacility("经济学院办公室")->addFacility("英语教室");
    buildings[9]->addFacility("理工实验室")->addFacility("理工机房");
    buildings[10]->addFacility("")->addFacility("信息共享中心")->addFacility("研修间")->addFacility("通宵自习室");

    int roadMessage[MAXSIZE][MAXSIZE] = {
        {0,  5, 17,  0,  0,  0,  0,  0,  0,  0,  0},    //0
        {0,  0,  0,  7,  0,  0,  0,  0,  0,  0,  0},    //1
        {0,  0,  0, 13,  0,  0, 21,  0,  0,  0, 26},    //2
        {0,  0,  0,  0,  9,  0, 22,  0,  0,  0,  0},    //3
        {0,  0,  0,  0,  0,  6,  7,  0,  0,  0,  0},    //4
        {0,  0,  0,  0,  0,  0,  4,  0,  0, 15,  0},    //5
        {0,  0,  0,  0,  0,  0,  0,  8,  0,  7, 16},    //6
        {0,  0,  0,  0,  0,  0,  0,  0, 10,  3, 14},    //7
        {0,  0,  0,  0,  0,  0,  0,  0,  0, 14,  5},    //8
        {0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},    //9
        {0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},    //10
    };
    map = new CampusMap(roadMessage, 11, 10, buildings);


}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_searchBuildingPushButton_clicked()
{
    SearchBuildingWidget* s = new SearchBuildingWidget(this->map);
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

