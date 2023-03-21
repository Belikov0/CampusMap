#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
//    QApplication a(argc, argv);
//    MainWindow w;
//    w.show();
//    return a.exec();

    //初始化建筑名称
    string extraBuilding = "图书馆";
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
        "博文楼",
        "图书馆",
    };
    Building* buildings[11];
    for (int i = 0; i < 11; i++){
        buildings[i] = new Building(i, buildingNames[i]);
    }
    buildings[0]->addFacility("")->addFacility("");
    buildings[1]->addFacility("洗衣房")->addFacility("理发店");
    buildings[2]->addFacility("")->addFacility("");
    buildings[3]->addFacility("")->addFacility("");
    buildings[4]->addFacility("")->addFacility("");
    buildings[5]->addFacility("")->addFacility("");
    buildings[6]->addFacility("")->addFacility("");
    buildings[7]->addFacility("")->addFacility("");
    buildings[8]->addFacility("")->addFacility("");
    buildings[9]->addFacility("")->addFacility("");
    buildings[10]->addFacility("")->addFacility("")->addFacility("");

    int roadMessage[MAXSIZE][MAXSIZE] = {
        {0,  5, 17, 19,  0,  0,  0,  0,  0,  0,  0},
        {0,  0, 20, 15,  0,  0,  0,  0,  0,  0,  0},
        {0,  0,  0, 11,  8, 12, 31,  0,  0,  0, 26},
        {0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},
        {0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},
        {0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},
        {0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},
        {0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},
        {0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},
        {0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},
        {0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},
    };
    CampusMap* m = new CampusMap(roadMessage, 11, 10, buildings);
//    m->findBuildingByBuildingName("商业街");
    m->findBuildingByfacility("洗衣房");
    m->insertBuilding()
    return 0;
}
