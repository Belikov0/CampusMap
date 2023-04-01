#include "mapdata.h"


MapData::MapData()
{

}

void MapData::setMap(CampusMap *_map)
{
    this->m = _map;
}

CampusMap *MapData::getMap()
{
    return this->m;
}

MapData::~MapData()
{

}
