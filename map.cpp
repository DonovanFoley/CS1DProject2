#include "map.h"
//hi
Map::Map() {}

Team &Map::insert(Team team)
{
    _teamsVector.append(team);
    _teamNameToIndex[team.teamName()] = team.id(); // new
    return _teamsVector.back();
}

// new method
int Map::findStadiumIndex(const QString &teamName) const
{
    return _teamNameToIndex.value(teamName, -1);
}

void Map::remove(Team team)
{
    for (int i = 0; i < _teamsVector.size(); i++) {
        if (_teamsVector[i].teamName() == team.teamName()) {
            _teamsVector.remove(i);
        }
    }
}

void Map::sort(Property property)
{
    Team temp;
    bool bubbleSort = false;
    for (int i = 0; i < _teamsVector.size() - 1; i++) {
        switch (property) {
        case 0: //Team name
            if (_teamsVector[i].teamName() > _teamsVector[i + 1].teamName())
                bubbleSort = true;
            break;
        case 1: //Stadium name
            if (_teamsVector[i].stadiumName() > _teamsVector[i + 1].stadiumName())
                bubbleSort = true;
            break;
        case 2: //Typology
            if (_teamsVector[i].typology() > _teamsVector[i + 1].typology())
                bubbleSort = true;
            break;
        case 3: //Date opened
            if (_teamsVector[i].dateOpened() > _teamsVector[i + 1].dateOpened())
                bubbleSort = true;
            break;
        case 4: //Seating capacity
            if (_teamsVector[i].seatingCapacity() > _teamsVector[i + 1].seatingCapacity())
                bubbleSort = true;
            break;
        }
        if (bubbleSort) {
            temp = _teamsVector[i];
            _teamsVector[i] = _teamsVector[i + 1];
            _teamsVector[i + 1] = temp;
            i = -1;
        }
        bubbleSort = false;
    }
}

void Map::clear()
{
    _teamsVector.clear();
}

int Map::size() const
{
    return _teamsVector.size();
}

Team *Map::operator[](QString teamName)
{
    for (int i = 0; i < _teamsVector.size(); i++) {
        if (_teamsVector[i].teamName() == teamName)
            return &_teamsVector[i];
    }
    return nullptr;
}

Team *Map::operator()(int index)
{
    return &_teamsVector[index];
}

const Team *Map::operator()(int index) const
{
    return &_teamsVector[index];
}

