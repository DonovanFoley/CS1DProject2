#ifndef MAP_H
#define MAP_H
//hi
#include <QVector>
#include <QHash>  // new
#include <QString> //new
#include "team.h"

enum Property { teamName, stadiumName, typology, dateOpened, seatingCapacity };

class Map
{
public:
    Map();

    Team &insert(Team team);
    void remove(Team team);
    void sort(Property property);
    int findStadiumIndex(const QString &teamName) const; //new

    void clear();
    //template <typename T> T compare(T p1, T p2);
    int size() const;

    Team *operator[](QString teamName);
    Team *operator()(int index);
    const Team *operator()(int index) const;

private:
    QVector<Team> _teamsVector;
    QHash<QString, int> _teamNameToIndex; //new
};

#endif // MAP_H
