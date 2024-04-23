#ifndef TEAM_H
#define TEAM_H

#include <QString>
#include <QMap>

class Team
{
public:
    Team();
    Team(QString teamName, QString stadiumName, int seatingCapacity, QString location, QString playingSurface,
         QString league, int dateOpened, int distanceToField, QString typology, QString rooftype,
         QMap<QString, double> souvenirList);


    //Accessors
    QString teamName() { return _teamName; }
    QString stadiumName() { return _stadiumName; }
    int seatingCapacity() { return _seatingCapacity; }
    QString location() { return _location; }
    QString playingSurface() { return _playingSurface; }
    QString league() { return _league; }
    int dateOpened() { return _dateOpened; }
    int distanceToField() { return _distanceToField; }
    QString typology() { return _typology; }
    QString rooftype() { return _rooftype; }
    QMap<QString, double> souvenirList() { return _souvenirList; }
    bool TeamisInTrip() { return _isInTrip; }
    bool TeamisStartingTeam() { return _isStartingTeam; }


    //Mutators
    void setTeamName(QString teamName) { _teamName = teamName; }
    void setStadiumName(QString stadiumName) { _stadiumName = stadiumName; }
    void setSeatingCapacity(int seatingCapacity) { _seatingCapacity = seatingCapacity; }
    void setLocation(QString location) { _location = location; }
    void setPlayingSurface(QString playingSurface) { _playingSurface = playingSurface; }
    void setLeage(QString league) { _league = league; }
    void setDateOpened(int dateOpened) { _dateOpened = dateOpened; }
    void setDistanceToField(int distanceToField) { _distanceToField = distanceToField; }
    void setTypology(QString typology) { _typology = typology; }
    void setRooftype(QString rooftype) { _rooftype = rooftype; }

private:
    QString _teamName;
    QString _stadiumName;
    int _seatingCapacity;
    QString _location;
    QString _playingSurface;
    QString _league;
    int _dateOpened;
    int _distanceToField;
    QString _typology;
    QString _rooftype;
    QMap<QString, double> _souvenirList;
    bool _isInTrip = false;
    bool _isStartingTeam = false;
};

#endif // TEAM_H
