#ifndef TEAM_H
#define TEAM_H

#include <QString>
#include <QMap>

class Team
{
public:
    Team();



    //Accessors
    QString teamName();
    QString stadiumName();
    int seatingCapacity();
    QString location();
    QString playingSurface();
    QString league();
    int dateOpened();
    int distanceToField();
    QString typology();
    QString rooftype();
    QMap<QString, double> souvenirList();
    bool isInTrip();
    bool isStartingTeam();

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
    bool _isInTrip;
    bool _isStartingTeam;
};

#endif // TEAM_H
