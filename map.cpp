#include "map.h"

Map::Map() {}

void Map::insert(Team team)
{
    _teamsVector.append(team);
}


void Map::sort(Property property)
{
    int index = -1;
    Team copy;

    switch (property)
    {
    case teamNameh:
        for (int i = 0; i < _teamsVector.size(); i++)
        {
            for (int x = i; x < _teamsVector.size(); x++)
            {
                if (_teamsVector[i].teamName() < _teamsVector[x].teamName()) index = x;
            }
            if (index != -1)
            {
                copy = _teamsVector[i];
                _teamsVector[i] =_teamsVector[index];
                _teamsVector[index] = copy;
            }
            index = -1;
        }
        break;
    case stadiumName:
        break;
    }
}

int Map::size() { return _teamsVector.size(); }

Team& Map::operator[](QString teamName)
{
    for (int i = 0; i < _teamsVector.size(); i++)
    {
        if (_teamsVector[i].teamName() == teamName) return _teamsVector[i];
    }
    //return;
}

Team& Map::operator()(int index)
{
    return _teamsVector[index];
}
