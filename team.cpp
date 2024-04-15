#include "Team.h"

Team::Team() {}

//Accessors
QString Team::teamName() { return _teamName; }
QString Team::stadiumName() { return _stadiumName; }
int Team::seatingCapacity() { return _seatingCapacity; }
QString Team::location() { return _location; }
QString Team::playingSurface() { return _playingSurface; }
QString Team::league() { return _league; }
int Team::dateOpened() { return _dateOpened; }
int Team::distanceToField() { return _distanceToField; }
QString Team::typology() { return _typology; }
QString Team::rooftype() { return _rooftype; }
QMap<QString, double> Team::souvenirList() { return _souvenirList; }
bool Team::isInTrip() { return _isInTrip; }
bool Team::isStartingTeam() { return _isStartingTeam; }
