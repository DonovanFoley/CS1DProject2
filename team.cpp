#include "team.h"
//hi
Team::Team() {}

Team::Team(QString teamName,
           QString stadiumName,
           int seatingCapacity,
           QString location,
           QString state,
           QString playingSurface,
           QString league,
           int dateOpened,
           int distanceToField,
           QString typology,
           QString rooftype,
           QMap<QString, double> souvenirList)
{
    _teamName = teamName;
    _stadiumName = stadiumName;
    _seatingCapacity = seatingCapacity;
    _location = location;
    _state = state;
    _playingSurface = playingSurface;
    _league = league;
    _dateOpened = dateOpened;
    _distanceToField = distanceToField;
    _typology = typology;
    _rooftype = rooftype;
    _souvenirList = souvenirList;
}
