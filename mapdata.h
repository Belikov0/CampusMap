#ifndef MAPDATA_H
#define MAPDATA_H


#include "matgraph.h"


class MapData
{

public:
    MapData();

    void setMap(CampusMap* _map);
    CampusMap* getMap();
    ~MapData();


    CampusMap* m;
};

#endif // MAPDATA_H
