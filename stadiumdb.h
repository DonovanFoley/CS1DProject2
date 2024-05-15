#ifndef DBINTERFACE_H
#define DBINTERFACE_H

#include "graph.h"
#include "map.h"
#include "sqlite3.h"
#include "team.h"

#include <iostream>
#include <sstream>
#include <vector>

/**
 * @brief The StadiumsDB class manages database operations related to stadiums, including reading and writing team and souvenir information.
 */
class StadiumsDB
{
public:
    /**
     * @brief Constructs a StadiumsDB object and opens a connection to the specified database file.
     * @param dbfile The file path to the SQLite database.
     */
    StadiumsDB(const char *dbfile);

    /**
     * @brief Default constructor for StadiumsDB, initializes an instance without a database file.
     */
    StadiumsDB();

    /**
     * @brief Sets the database file for SQLite operations using a C-style string.
     * @param dbfile The file path to the SQLite database.
     */
    void set_file(const char *dbfile);

    /**
     * @brief Sets the database file for SQLite operations using a QString.
     * @param dbfile The file path to the SQLite database.
     */
    void set_file(const QString dbfile);

    /**
     * @brief Returns the number of stadiums in the database.
     * @return Integer representing the number of stadiums.
     */
    int num_stadiums();

    /**
     * @brief Populates a Map object with teams from the database.
     * @param map Reference to a Map object to be populated with Team data.
     */
    void populate_teams(Map &map);

    /**
     * @brief Populates a Map object with souvenir information from the database.
     * @param map Reference to a Map object to be populated with souvenir data.
     */
    void populate_souvenirs(Map &map);

    /**
     * @brief Modifies existing stadium information in the database.
     * @param team Reference to a Team object containing the updated stadium information.
     */
    void modify_stadium_info(Team &team);

    /**
     * @brief Generates a graph representing the connections between stadiums based on the provided Map of teams.
     * @param map Reference to a Map object containing teams and their stadiums.
     * @return A Graph object representing stadium connections.
     */
    Graph make_graph(const Map &map);

protected:
    /**
     * @brief Prepares an SQL statement for execution.
     * @param query The SQL query as a standard string.
     */
    void prepare_statement(std::string query);

    /**
     * @brief Finalizes the current prepared statement, cleaning up resources.
     */
    void finalize_statement();

private:
    sqlite3 *db_; ///< Pointer to the SQLite database connection.
    sqlite3_stmt *state_; ///< Pointer to the SQLite prepared statement object.
    int status_; ///< Status of the last SQLite operation.

    char *file_loc_; ///< Location of the SQLite database file.
};

#endif // DBINTERFACE_H
