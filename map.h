#ifndef MAP_H
#define MAP_H

#include <QVector>
#include "team.h"

enum Property {teamNameh, stadiumName, rooftype};

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

/*
template <typename T> T Map::compare(T p1, T p2)
{
    if (p1 > p2) return p1;
    return p2;
}*/

#endif // MAP_H
