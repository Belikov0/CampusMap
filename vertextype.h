#ifndef VERTEXTYPE_H
#define VERTEXTYPE_H
#define MAXFACILITIES 10
#include <string>
#include <QString>
#include <iostream>
using namespace std;

typedef class VertexType
{
    int no;
    int facilityNumber;
    string buildingName;
    string facilities[MAXFACILITIES];
public:
    VertexType();
    VertexType(int _no, string _buildingName);
    //根据建筑名称、设施名称和设施数量创建建筑结点
    VertexType(int _no, string _buildingName, string _facilities[], int _facilityNumber);
    //重载类型的相等运算符
    bool operator==(VertexType& _v)const;

    //成员变量的setter
    void setNo(int _no);
    void setFacilityNumber(int _facilityNumber);
    void setBuildingName(string _buildingName);

    //成员变量的getter
    int getNo()const;
    int getFacilityNumber()const;
    string getBuildingName()const;

    //给该建筑添加设施
    VertexType* addFacility(string _facilityName);

    bool delFacility(string _facilityName);

    //判断该设施是否属于该建筑
    bool isInclude(string _facilityName)const;

    //获得该建筑的编号（实际上在邻接矩阵中，已经使用下标来表示编号）
    int getNumber()const;



    //显示建筑本身的信息
    void showInnerMessage()const;
}Building;

#endif // VERTEXTYPE_H
