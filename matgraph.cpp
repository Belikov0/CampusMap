#include "matgraph.h"

MatGraph::MatGraph()
{

}

MatGraph::MatGraph(int _g[MAXSIZE][MAXSIZE], int _buildingNumber, int _roadNumber, Building* _buildings[])
 : buildingNumber(_buildingNumber), roadNumber(_roadNumber)
{
    for (int i = 0; i<this->getVertexNumber(); i++){
        for (int j = 0; j<this->getVertexNumber(); j++){
            if(i == j){
                this->roads[i][j] = 0;
            }else if(_g[i][j] == 0 && i < j){
                this->roads[i][j] = INF;
                this->roads[i][j] = INF;
            }else if (i < j){
                this->roads[i][j] = _g[i][j];
                this->roads[j][i] = _g[i][j];
            }
        }
    }
    for (int i = 0; i < this->getVertexNumber(); i++){
        this->buildings[i] = _buildings[i];
    }

}

int MatGraph::getVertexNumber() const
{
    return this->buildingNumber;
}

int MatGraph::getEdgeNumber() const
{
    return this->roadNumber;
}

int MatGraph::getBuildingIdByName(string buildingName)
{
    for (int i = 0; i < this->buildingNumber; i++){
        if (this->buildings[i]->getBuildingName() == buildingName){
            return i;
        }
    }
    return -1;
}

string MatGraph::getBuildingNameByNumber(int _no)
{
    return this->buildings[_no]->getBuildingName();
}

void MatGraph::findBuildingByBuildingName(string _buildingName)
{
    int id = this->getBuildingIdByName(_buildingName);
    showMessage(id);
}

void MatGraph::findBuildingByBuildingId(int _id)
{
    showMessage(_id);
}

void MatGraph::findBuildingByfacility(string _facilityName)
{
    for (int i = 0; i < this->buildingNumber; i++){
        if (this->buildings[i]->isInclude(_facilityName)){
            int no = i;
            showMessage(no);
        }
    }
}

void MatGraph::showMessage(int _id)
{
    //显示建筑自身的信息
    this->buildings[_id]->showInnerMessage();
    //搜索图，显示路径信息
    string s = "可通往的建筑：\n";
    for (int i = 0; i < buildingNumber; i++){
        if (this->roads[_id][i] != INF && this->roads[_id][i] != 0){
            s += ("\t" + this->getBuildingNameByNumber(i) + "\t距离：" + to_string(this->roads[_id][i]) + "\n");
        }
    }
    cout << s;

}

bool MatGraph::insertBuilding(string _buildingName)
{

}

