#ifndef MAP_H
#define MAP_H

#include <QVector>
#include "team.h"

enum Property {teamName, stadiumName, typology, dateOpened, seatingCapacity};

class Map
{
public:
    Map();

    void insert(Team team);
    void sort(Property property);
    //template <typename T> T compare(T p1, T p2);
    int size();

    Team& operator[](QString teamName);
    Team& operator()(int index);

private:
    QVector<Team> _teamsVector;
};

#endif // MAP_H
