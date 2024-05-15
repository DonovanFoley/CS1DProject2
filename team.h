#ifndef TEAM_H
#define TEAM_H
//hi
#include <QMap>
#include <QString>


/**
 * @brief The Team class represents a sports team and includes various details about the team and its stadium.
 */
class Team
{
public:
    /**
     * @brief Default constructor for the Team class.
     */
    Team();

    /**
     * @brief Constructor that initializes a Team with detailed attributes.
     * @param teamName Name of the team.
     * @param stadiumName Name of the team's stadium.
     * @param seatingCapacity Seating capacity of the stadium.
     * @param location Geographic location of the stadium.
     * @param playingSurface Type of playing surface in the stadium.
     * @param league League in which the team participates.
     * @param dateOpened Year the stadium was opened.
     * @param distanceToField Distance from the city center to the stadium.
     * @param typology Architectural typology of the stadium.
     * @param rooftype Type of the roof of the stadium.
     * @param souvenirList List of souvenirs and their prices offered at the stadium.
     */
    Team(QString teamName,
         QString stadiumName,
         int seatingCapacity,
         QString location,
         QString playingSurface,
         QString league,
         int dateOpened,
         int distanceToField,
         QString typology,
         QString rooftype,
         QMap<QString, double> souvenirList);


    // Accessors
    /**
     * @brief Retrieves the team ID.
     * @return The ID of the team as an integer.
     */
    int id() const { return _id; }

    /**
     * @brief Retrieves the team name.
     * @return The name of the team as a QString.
     */
    QString teamName() { return _teamName; }

    /**
     * @brief Retrieves the name of the team's stadium.
     * @return The name of the stadium as a QString.
     */
    QString stadiumName() { return _stadiumName; }

    /**
     * @brief Retrieves the seating capacity of the stadium.
     * @return The seating capacity as an integer.
     */
    int seatingCapacity() { return _seatingCapacity; }

    /**
     * @brief Retrieves the location of the stadium.
     * @return The location as a QString.
     */
    QString location() { return _location; }

    /**
     * @brief Retrieves the type of playing surface of the stadium.
     * @return The playing surface as a QString.
     */
    QString playingSurface() { return _playingSurface; }

    /**
     * @brief Retrieves the league of the team.
     * @return The league as a QString.
     */
    QString league() { return _league; }

    /**
     * @brief Retrieves the year the stadium was opened.
     * @return The opening year as an integer.
     */
    int dateOpened() { return _dateOpened; }

    /**
     * @brief Retrieves the distance from the city center to the stadium.
     * @return The distance as an integer.
     */
    int distanceToField() { return _distanceToField; }

    /**
     * @brief Retrieves the architectural typology of the stadium.
     * @return The typology as a QString.
     */
    QString typology() { return _typology; }

    /**
     * @brief Retrieves the type of the stadium's roof.
     * @return The roof type as a QString.
     */
    QString rooftype() { return _rooftype; }

    /**
     * @brief Retrieves the list of souvenirs and their prices.
     * @return A QMap where keys are souvenir names and values are their prices.
     */
    QMap<QString, double> souvenirList() { return _souvenirList; }

    /**
     * @brief Checks if the team is currently included in a trip plan.
     * @return True if the team is included in a trip plan, otherwise false.
     */
    bool isInTrip() { return _isInTrip; }

    /**
     * @brief Checks if this team's stadium is the starting point in a trip.
     * @return True if this team's stadium is the starting point, otherwise false.
     */
    bool isStartingTeam() { return _isStartingTeam; }

    /**
     * @brief Provides a reference to the team's souvenir list for modification.
     * @return Reference to the QMap storing souvenir names and their prices.
     */
    QMap<QString, double> &souvenirListRef() { return _souvenirList; }

    //Mutators
    /**
     * @brief Sets the team ID.
     * @param id The new ID for the team.
     */
    void setId(int id) { _id = id; }

    /**
     * @brief Sets the team name.
     * @param teamName The new name for the team.
     */
    void setTeamName(QString teamName) { _teamName = teamName; }

    /**
     * @brief Sets the name of the team's stadium.
     * @param stadiumName The new name for the stadium.
     */
    void setStadiumName(QString stadiumName) { _stadiumName = stadiumName; }

    /**
     * @brief Sets the seating capacity of the stadium.
     * @param seatingCapacity The new seating capacity.
     */
    void setSeatingCapacity(int seatingCapacity) { _seatingCapacity = seatingCapacity; }

    /**
     * @brief Sets the location of the stadium.
     * @param location The new location for the stadium.
     */
    void setLocation(QString location) { _location = location; }

    /**
     * @brief Sets the type of playing surface at the stadium.
     * @param playingSurface The new playing surface type.
     */
    void setPlayingSurface(QString playingSurface) { _playingSurface = playingSurface; }

    /**
     * @brief Sets the league of the team.
     * @param league The new league for the team.
     */
    void setLeague(QString league) { _league = league; }

    /**
     * @brief Sets the year the stadium was opened.
     * @param dateOpened The new opening year for the stadium.
     */
    void setDateOpened(int dateOpened) { _dateOpened = dateOpened; }

    /**
     * @brief Sets the distance from the city center to the stadium.
     * @param distanceToField The new distance to the stadium.
     */
    void setDistanceToField(int distanceToField) { _distanceToField = distanceToField; }

    /**
     * @brief Sets the architectural typology of the stadium.
     * @param typology The new typology for the stadium.
     */
    void setTypology(QString typology) { _typology = typology; }

    /**
     * @brief Sets the type of roof on the stadium.
     * @param rooftype The new roof type for the stadium.
     */
    void setRooftype(QString rooftype) { _rooftype = rooftype; }

    /**
     * @brief Sets the list of souvenirs and their prices.
     * @param souvenirList The new list of souvenirs and prices.
     */
    void setSouvenirList(QMap<QString, double> souvenirList) { _souvenirList = souvenirList; }

    /**
     * @brief Toggles the inclusion of the team in a trip plan.
     * @param isInTrip The new state indicating whether the team is included in a trip plan.
     */
    void toggleIsInTrip(bool isInTrip) { _isInTrip = isInTrip; }

private:
    int _id; ///< ID of the team.
    QString _teamName; ///< Name of the team.
    QString _stadiumName;  ///< Name of the team's stadium.
    int _seatingCapacity; ///< Seating capacity of the stadium.
    QString _location; ///< Geographic location of the stadium.
    QString _playingSurface; ///< Type of playing surface at the stadium.
    QString _league; ///< League in which the team participates.
    int _dateOpened;  ///< Year the stadium was opened.
    int _distanceToField; ///< Distance from the city center to the stadium.
    QString _typology; ///< Architectural typology of the stadium.
    QString _rooftype; ///< Type of roof on the stadium.
    QMap<QString, double> _souvenirList; ///< List of souvenirs and their prices.
    bool _isInTrip = false; ///< Indicates if the team is currently included in a trip plan.
    bool _isStartingTeam = false; ///< Indicates if this team's stadium is the starting point in a trip.
};

#endif // TEAM_H
