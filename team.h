#ifndef TEAM_H
#define TEAM_H
//hi
#include <QMap>
#include <QString>

class Team
{
public:
    Team();
    Team(QString teamName,
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
         QMap<QString, double> souvenirList);

    //Accessors
    int id() const { return _id; }
    QString teamName() { return _teamName; }
    QString stadiumName() { return _stadiumName; }
    int seatingCapacity() { return _seatingCapacity; }
    QString location() { return _location; }
    QString state() { return _state; }
    QString playingSurface() { return _playingSurface; }
    QString league() { return _league; }
    int dateOpened() { return _dateOpened; }
    int distanceToField() { return _distanceToField; }
    QString typology() { return _typology; }
    QString rooftype() { return _rooftype; }
    QMap<QString, double> souvenirList() { return _souvenirList; }
    bool isInTrip() { return _isInTrip; }
    bool isStartingTeam() { return _isStartingTeam; }

    QMap<QString, double> &souvenirListRef() { return _souvenirList; }

    //Mutators
    void setId(int id) { _id = id; }
    void setTeamName(QString teamName) { _teamName = teamName; }
    void setStadiumName(QString stadiumName) { _stadiumName = stadiumName; }
    void setSeatingCapacity(int seatingCapacity) { _seatingCapacity = seatingCapacity; }
    void setLocation(QString location) { _location = location; }
    void setState(QString state) { _state = state; }
    void setPlayingSurface(QString playingSurface) { _playingSurface = playingSurface; }
    void setLeague(QString league) { _league = league; }
    void setDateOpened(int dateOpened) { _dateOpened = dateOpened; }
    void setDistanceToField(int distanceToField) { _distanceToField = distanceToField; }
    void setTypology(QString typology) { _typology = typology; }
    void setRooftype(QString rooftype) { _rooftype = rooftype; }
    void setSouvenirList(QMap<QString, double> souvenirList) { _souvenirList = souvenirList; }
    void toggleIsInTrip(bool isInTrip) { _isInTrip = isInTrip; }

private:
    int _id;
    QString _teamName;
    QString _stadiumName;
    int _seatingCapacity;
    QString _location;
    QString _state;
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
