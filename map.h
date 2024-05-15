#ifndef MAP_H
#define MAP_H

#include <QHash>
#include <QVector>
#include "team.h"

/**
 * @brief Property enum to specify sorting and comparison properties for teams.
 */
enum Property { teamName, stadiumName, typology, dateOpened, seatingCapacity };

/**
 * @brief The Map class manages a collection of Team objects using a vector and a hash map for efficient access and manipulation.
 */
class Map
{
public:
    /**
     * @brief Constructs a Map object.
     */
    Map();

    /**
     * @brief Inserts a Team object into the map.
     *
     * If the team already exists, it will replace the old team.
     * @param team The Team to be inserted.
     * @return A reference to the Team object within the map.
     */
    Team &insert(Team team);

    /**
     * @brief Removes a Team object from the map.
     *
     * @param team The Team to be removed.
     */
    void remove(Team team);

    /**
     * @brief Sorts the internal vector of teams based on the specified property.
     *
     * @param property The Property by which to sort the teams.
     */
    void sort(Property property);

    /**
     * @brief Clears all entries from the map.
     */
    void clear();

    /**
     * @brief Returns the number of teams in the map.
     *
     * @return The number of teams as an integer.
     */
    int size() const;

    /**
     * @brief Overloaded subscript operator to access Team by team name.
     *
     * @param teamName The name of the team.
     * @return Pointer to the Team if found, nullptr otherwise.
     */
    Team *operator[](QString teamName);

    /**
     * @brief Overloaded function call operator to access Team by index.
     *
     * @param index The index of the team in the vector.
     * @return Pointer to the Team if index is valid, nullptr otherwise.
     */
    Team *operator()(int index);

    /**
     * @brief Overloaded function call operator to access const Team by index.
     *
     * @param index The index of the team in the vector.
     * @return Const pointer to the Team if index is valid, nullptr otherwise.
     */
    const Team *operator()(int index) const;

    /**
     * @brief Finds the index of a stadium based on the team name.
     *
     * @param teamName The name of the team whose stadium index is to be found.
     * @return The index of the stadium if found, -1 otherwise.
     */
    int findStadiumIndex(const QString &teamName) const;

private:
    QVector<Team> _teamsVector; ///< Vector storing all teams.
    QHash<QString, int> _teamNameToIndex; ///< Hash map linking team names to their indices in the vector.
};

#endif // MAP_H
