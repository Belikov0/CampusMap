#ifndef MATGRAPH_H
#define MATGRAPH_H
#define MAXSIZE 50
#include <string>
#include "vertextype.h"
#define MAXFACILITIES 10
#define INF 0x7fffffff
using namespace std;

typedef class MatGraph
{
    int roads[MAXSIZE][MAXSIZE];
    int buildingNumber;
    int roadNumber;
    Building* buildings[MAXSIZE];

public:
    MatGraph();
    MatGraph(int _g[MAXSIZE][MAXSIZE], int _buildingNumber, int _roadNumber, Building* _buildings[]);
    //成员变量的setter
    void setBuildingNumber();
    void setRoadNumber();

    //成员变量的getter
    int getVertexNumber()const;
    int getEdgeNumber()const;

//根据建筑编号获取建筑名称，以及根据建筑名称获取编号的方法
    int getBuildingIdByName(string _buildingName);
    string getBuildingNameByNumber(int _no);

//根据不同的属性来查询建筑物的信息，显示该建筑可以通向的其它建筑以及距离
    //根据建筑名字查找
    void findBuildingByBuildingName(string _buildingName);
    //根据建筑编号查找
    void findBuildingByBuildingId(int _no);
    //根据建筑所含设施查找（重点实现）
    void findBuildingByfacility(string _facilityName);
    //根据建筑的名字，在图中搜索所有的路径以及结点
    void showMessage(int _no);

//插入建筑或者路径
    //使用建筑名和其属性插入
    bool insertBuilding(string _buildingName);
    //插入建筑之间的路径
    bool insertRoad(Building _b1, Building _b2, int _roadLength);
//删除建筑或者路径
    //删除建筑，以及建筑到其它建筑的所有路径（图的删除算法）
    bool deleteBuilding(Building _b);
    bool deleteBuilding(string _buildingName);
    //删除某两个建筑之间的路径，选择第一个建筑后，第二个下拉框中会显示能够到达的所有建筑
    bool deleteRoad(string _buildingName1, string _buildingName2);

//导游算法
    //使用深度优先搜索算法，计算出两者之间所有的路径，并推荐最优路径,内部使用编号完成路径
    void getPaths(string _buildingName1, string _buildingName2);
    //使用深度优先搜索算法导游一个点出发游历所有建筑的路径，并标识最短路径
    void guidingRoute(string _buildingName);
}CampusMap;

#endif // MATGRAPH_H
