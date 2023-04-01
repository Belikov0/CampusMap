#include "vertextype.h"

VertexType::VertexType() : buildingName(""), facilityNumber(0)
{

}

VertexType::VertexType(int _no, string _buildingName)
: no(_no), buildingName(_buildingName), facilityNumber(0)
{

}

VertexType::VertexType(int _no, string _buildingName, string _facilities[], int _facilityNumber)
    : buildingName(_buildingName), facilityNumber(_facilityNumber)
{
    for (int i = 0; i < this->facilityNumber; i++){
        this->facilities[i] = string(_facilities[i]);
    }
}

void VertexType::setNo(int _no)
{
    this->no = _no;
}

void VertexType::setFacilityNumber(int _facilityNumber)
{
    this->facilityNumber = _facilityNumber;
}

void VertexType::setBuildingName(string _buildingName)
{
    this->buildingName = _buildingName;
}

int VertexType::getNo()const
{
    return this->no;
}

int VertexType::getFacilityNumber()const
{
    return this->facilityNumber;
}

string VertexType::getBuildingName()const
{
    return this->buildingName;
}

VertexType* VertexType::addFacility(string _facilityName)
{
    this->facilities[facilityNumber++] = _facilityName;
    //用于链式调用
    return this;
}

bool VertexType::delFacility(string _facilityName)
{
    if (facilityNumber == 0)
        return true;
    facilityNumber--;
    return true;
}

bool VertexType::isInclude(string _facilityName) const
{
    for (int i = 0; i < facilityNumber; i++){
        if (_facilityName == facilities[i])
            return true;
    }
    return false;
}

int VertexType::getNumber() const
{
    return this->no;
}

void VertexType::showInnerMessage()const
{
    //拼接字符串
    string s = "建筑名：\n\t" + this->getBuildingName()
            + "\n拥有设施: \n";
    for (int i = 0; i < this->facilityNumber; i++){
        s += string("\t" + this->facilities[i] + "\n");
    }
    cout << s;
}
