#include "stadiumdb.h"
#include <QDebug>
#include <iostream>
#include <sstream>

StadiumsDB::StadiumsDB(const QString& dbfile) {
    set_file(dbfile);
}

StadiumsDB::StadiumsDB(const char* dbfile) {
    set_file(dbfile);
}

StadiumsDB::StadiumsDB() : db_(nullptr), state_(nullptr), fileLoc_(nullptr, free) {
}

StadiumsDB::~StadiumsDB() {
    finalize_statement();  // Ensure all resources are cleaned up
    if (db_) {
        sqlite3_close(db_);
    }
}

void StadiumsDB::set_file(const QString &dbfile) {
    set_file(dbfile.toStdString().c_str());
}

void StadiumsDB::set_file(const char* dbfile) {
    fileLoc_.reset(strdup(dbfile));
}

int StadiumsDB::num_stadiums() {
    prepare_statement("SELECT COUNT(*) FROM stadium");
    if (status_ == SQLITE_OK && sqlite3_step(state_) == SQLITE_ROW) {
        int count = sqlite3_column_int(state_, 0);
        finalize_statement();
        return count;
    }
    finalize_statement();
    return 0;
}

/*void StadiumsDB::populate_teams(Map& teams) {
    std::cout << "Populating teams from database..." << std::endl;

    prepare_statement("SELECT * FROM stadium");
    while (sqlite3_step(state_) == SQLITE_ROW) {  // Continue until all rows have been processed
        Team team;
        modify_stadium_info(team);  // Populate team information from the current row
        teams.insert(team);         // Insert the team into the map
        std::cout << "Loaded team: " << team.teamName().toStdString() << std::endl; // Output the team name to the console

        status_ = sqlite3_step(state_); // Move to the next row
    }

    if (status_ == SQLITE_DONE) {
        std::cout << "All teams populated successfully." << std::endl;
    } else {
        std::cerr << "Error populating teams: " << sqlite3_errmsg(db_) << std::endl; // Print any errors encountered
    }

    finalize_statement();
}*/
void StadiumsDB::populate_teams(Map &teams)
{
    teams.clear();
    prepare_statement("SELECT * FROM stadium"); // Prepare to select all stadiums

    std::cout << "Populating teams from database..." << std::endl;

    status_ = sqlite3_step(state_); // Execute the SQL query
    while (status_ == SQLITE_ROW) {  // Continue until all rows have been processed
        Team team;
        modify_stadium_info(team);  // Populate team information from the current row
        teams.insert(team);         // Insert the team into the map
        std::cout << "Loaded team: " << team.teamName().toStdString() << std::endl; // Output the team name to the console

        status_ = sqlite3_step(state_); // Move to the next row
    }

    if (status_ == SQLITE_DONE) {
        std::cout << "All teams populated successfully." << std::endl;
    } else {
        std::cerr << "Error populating teams: " << sqlite3_errmsg(db_) << std::endl; // Print any errors encountered
    }

    finalize_statement(); // Clean up the prepared statement
}

void StadiumsDB::populate_souvenirs(Map &teams)
{
    for (int i = 0; i < teams.size(); ++i) //for all teams
    {
        auto team = teams(i);
        team->souvenirListRef().clear();

        std::stringstream state;
        state << "SELECT name, price FROM souvenir WHERE stadium_id = " << team->id() << ";";

        prepare_statement(state.str());

        status_ = sqlite3_step(state_); //do until out of rows for table
        while (status_ != SQLITE_DONE) {
            QString name(reinterpret_cast<const char *>(sqlite3_column_text(state_, 0)));
            team->souvenirListRef()[name] = sqlite3_column_double(state_, 1);
            status_ = sqlite3_step(state_);
        }

        finalize_statement();
    }
}

/*void StadiumsDB::modify_stadium_info(Team &stadium)
{
    stadium.setId(sqlite3_column_int(state_, 0));
    stadium.setTeamName(QString(reinterpret_cast<const char *>(sqlite3_column_text(state_, 1))));
    stadium.setStadiumName(QString(reinterpret_cast<const char *>(sqlite3_column_text(state_, 2))));
    stadium.setSeatingCapacity(sqlite3_column_int(state_, 3));
    stadium.setLocation(QString(reinterpret_cast<const char *>(sqlite3_column_text(state_, 4))));
    stadium.setPlayingSurface(
        QString(reinterpret_cast<const char *>(sqlite3_column_text(state_, 6))));
    stadium.setLeague(QString(reinterpret_cast<const char *>(sqlite3_column_text(state_, 7))));
    stadium.setDateOpened(sqlite3_column_int(state_, 8));
    stadium.setDistanceToField(sqlite3_column_int(state_, 9));
    stadium.setTypology(QString(reinterpret_cast<const char *>(sqlite3_column_text(state_, 10))));
    stadium.setRooftype(QString(reinterpret_cast<const char *>(sqlite3_column_text(state_, 11))));
}*/

// Utility function to trim whitespace from a QString
QString StadiumsDB::trim(const QString &str)
{
    return str.trimmed();
}

void StadiumsDB::modify_stadium_info(Team &team)
{
    team.setId(sqlite3_column_int(state_, 0));
    team.setTeamName(trim(QString::fromUtf8(reinterpret_cast<const char *>(sqlite3_column_text(state_, 1)))));
    team.setStadiumName(trim(QString::fromUtf8(reinterpret_cast<const char *>(sqlite3_column_text(state_, 2)))));
    team.setSeatingCapacity(sqlite3_column_int(state_, 3));
    team.setLocation(trim(QString::fromUtf8(reinterpret_cast<const char *>(sqlite3_column_text(state_, 4)))));
    team.setPlayingSurface(trim(QString::fromUtf8(reinterpret_cast<const char *>(sqlite3_column_text(state_, 6)))));
    team.setLeague(trim(QString::fromUtf8(reinterpret_cast<const char *>(sqlite3_column_text(state_, 7)))));
    team.setDateOpened(sqlite3_column_int(state_, 8));
    team.setDistanceToField(sqlite3_column_int(state_, 9));
    team.setTypology(trim(QString::fromUtf8(reinterpret_cast<const char *>(sqlite3_column_text(state_, 10)))));
    team.setRooftype(trim(QString::fromUtf8(reinterpret_cast<const char *>(sqlite3_column_text(state_, 11)))));
}

Graph StadiumsDB::make_graph(const Map& teams) {
    Graph teams_edges;

    for(int i = 0; i < teams.size(); ++i)
    {
        std::stringstream state;
        state << "SELECT * FROM stadium_Distance WHERE stadium_id1 = " << teams(i)->id() << ";";

        prepare_statement(state.str());

        status_ = sqlite3_step(state_);
        while(status_ != SQLITE_DONE) {
            int origin = sqlite3_column_int(state_, 0);
            int dest =   sqlite3_column_int(state_, 1);
            int w =      sqlite3_column_int(state_, 2);

            teams_edges.add_edge_one_way(origin, dest, w);
            status_ = sqlite3_step(state_);
        }

        finalize_statement();
    }

    return teams_edges;
}

void StadiumsDB::prepare_statement(const std::string& statement) {
    if (db_) sqlite3_close(db_);
    status_ = sqlite3_open(fileLoc_.get(), &db_);

    if (status_ != SQLITE_OK) {
        std::cout << "Failed to prepare statement: " << sqlite3_errmsg(db_) << std::endl;
    } else {
        std::cout << "Statement prepared successfully." << std::endl;
    }

    if (status_ != SQLITE_OK) return;
    status_ = sqlite3_prepare_v2(db_, statement.c_str(), -1, &state_, nullptr);
}

void StadiumsDB::finalize_statement() {
    if (state_) {
        sqlite3_finalize(state_);
        state_ = nullptr;
    }
    if (db_) {
        sqlite3_close(db_);
        db_ = nullptr;
    }
}

