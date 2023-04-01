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
                this->roads[j][i] = INF;
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
    //插入失败的情况
    if (this->getVertexNumber() == MAXSIZE)
        return false;

    //插入成功的情况
    this->buildingNumber++;
    for (int i = 0; i < this->getVertexNumber(); i++){
        this->roads[i][this->getVertexNumber()] = INF;
        this->roads[this->getVertexNumber()][i] = INF;
    }
    this->roads[this->getVertexNumber()-1][this->getVertexNumber()-1] = 0;
    Building* tmp = new Building(this->getVertexNumber()-1, _buildingName);
    this->buildings[this->getVertexNumber()-1] = tmp;
    return true;
}

bool MatGraph::insertBuilding(Building* _building)
{
    //插入失败的情况
    if (this->getVertexNumber() == MAXSIZE)
        return false;

    this->buildingNumber++;
    for (int i = 0; i < this->getVertexNumber(); i++){
        this->roads[i][this->getVertexNumber()] = INF;
        this->roads[this->getVertexNumber()][i] = INF;
    }
    this->roads[this->getVertexNumber()-1][this->getVertexNumber()-1] = 0;
    this->buildings[this->getVertexNumber()-1] = _building;
    return true;
}

bool MatGraph::insertRoad(string _buildingName1, string _buildingName2, int _roadLength)
{
    return this->rectifyRoadLength(_buildingName1, _buildingName2, _roadLength);
}

bool MatGraph::rectifyRoadLength(string _buildingName1, string _buildingName2, int _newRoadLength)
{
    int id1 = this->getBuildingIdByName(_buildingName1);
    int id2 = this->getBuildingIdByName(_buildingName2);
    roads[id1][id2] = _newRoadLength;
    return true;
}

bool MatGraph::deleteBuilding(string _buildingName)
{
    //获取要删除的建筑的编号
    int id = this->getBuildingIdByName(_buildingName);
    int lastId = getVertexNumber()-1;
    if (id == lastId){
        this->buildingNumber--;
        return true;
    }

    buildings[id] = buildings[lastId];
    buildings[id]->setNo(id);

    //修改邻接矩阵中的行和列
    for (int i = 0; i < getVertexNumber(); i++){
        this->roads[id][i] = this->roads[lastId][i];
        this->roads[i][id] = this->roads[i][lastId];
    }
    this->roads[id][id] = 0;
    this->buildingNumber--;
    this->buildings[buildingNumber] = nullptr;
    return true;
}

bool MatGraph::deleteRoad(string _buildingName1, string _buildingName2)
{
    return this->rectifyRoadLength(_buildingName1, _buildingName2, INF);
}

bool MatGraph::deleteFacility(string _buildingName, string _facilityName)
{
    int id = this->getBuildingIdByName(_buildingName);
    if (this->buildings[id]->delFacility(_facilityName))
            return true;
    return false;
}

void MatGraph::getPaths(string _srcBuilding, string _destBuilding)
{
    int src = getBuildingIdByName(_srcBuilding);
    int dest = getBuildingIdByName(_destBuilding);

    int vis[this->getVertexNumber()];
    memset(vis, 0, sizeof vis);

    vector<int> curr;            //存储路径的节点
    vector<vector<int>> allPaths;   //存储所有路径
    vector<int> minPath;        //存储最短路径

    //标记出发点已经被访问
    vis[src] = 1;
    curr.push_back(src);

    //使用深度优先搜索获得所有路径
    dfs(src, dest, vis, 0, curr, allPaths, false);
    //在所有路径中搜索最短路径
    showAllPaths(src, allPaths, minPath);

}

void MatGraph::dfs(int _src, int _dest, int _vis[],
                   int _curDis, vector<int> _curr, vector<vector<int> > &_allPaths, bool isGuidingRoute)
{
    int res = INF;
    _vis[_src] = 1;  //标记当前结点为已访问

    //到达终点，将路径结点添加
    if (_src == _dest){
        if ((!isGuidingRoute || (isGuidingRoute && _curr.size() == getVertexNumber())))
            _allPaths.push_back(_curr);
        return;
    }

    for (int i = 0; i < getVertexNumber(); i++){
        if (!_vis[i] && _src !=i && roads[_src][i] != INF){
            _curr.push_back(i); //将i加入路径
            dfs(i, _dest, _vis, _curDis+roads[_src][i], _curr, _allPaths, isGuidingRoute);
            _curr.pop_back();//回溯
            _vis[i]=0;
        }
    }
}

void MatGraph::showAllPaths(int _src, vector<vector<int> > &_allPaths, vector<int> _minPath)
{
    int minDis = INF;
    int cur;
    //遍历所有路径获得最短路径
    for (int i = 0; i < _allPaths.size(); i++){
        int cur = _src;
        //要在GUI上显示最短路径
        int dis = 0;
        for (int j = 0; j < _allPaths[i].size(); j++){
            if (j != 0)
                cout << " --> ";
            int ne = _allPaths[i][j];
            cout << this->buildings[ne]->getBuildingName();
            dis += this->roads[cur][ne];
            cur = ne;
        }
        cout << endl << "Distance: " << dis << endl << endl;
        _minPath = minDis > dis ? _allPaths[i] : _minPath;
        minDis = minDis > dis ? dis : minDis;
    }

    //显示最短路径
    //corresponding codes here
    cur = _src;
    cout << "最短路径" << endl;
    for(int i = 0;i < _minPath.size(); i++){
        if (i != 0)
            cout << " --> ";
        int ne = _minPath[i];
        cout << this->buildings[ne]->getBuildingName();
        cur = ne;
    }
    cout << endl << "最短距离" << minDis << endl;
    cout << "路线数量" << _allPaths.size() << endl;
}

void MatGraph::guidingRoute(string _buildingName)
{
    int src = getBuildingIdByName(_buildingName);
    int vis[this->getVertexNumber()];
    memset(vis, 0, sizeof vis);

    vector<int> curr;            //存储路径的节点
    vector<vector<int>> allPaths;   //存储所有路径
    vector<int> minPath;        //存储最短路径

    //标记出发点已经被访问
    curr.push_back(src);
    for (int i = 0; i < getVertexNumber(); i++){
        dfs(src, i, vis, 0, curr, allPaths, true);
    }
    showAllPaths(src, allPaths, minPath);
}

