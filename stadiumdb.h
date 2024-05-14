#ifndef STADIUMSDB_H
#define STADIUMSDB_H

#include <QString>
#include "graph.h"
#include "map.h"
#include "team.h"
#include <memory> // Include for std::unique_ptr
#include <sqlite3.h>
#include <vector>

class StadiumsDB
{
public:
    explicit StadiumsDB(const QString &dbfile); // Constructor for QString
    explicit StadiumsDB(const char *dbfile);    // Constructor for C-style string
    StadiumsDB();
    ~StadiumsDB(); // Destructor to handle cleanup

    void set_file(const QString &dbfile); // For setting the file using QString
    void set_file(const char *dbfile);    // For setting the file using C-style string

    int num_stadiums();

    void populate_teams(Map &teams);
    void populate_souvenirs(Map &teams);

    void modify_stadium_info(Team &team);

    Graph make_graph(const Map &teams);

protected:
    void prepare_statement(const std::string &statement);
    void finalize_statement();

private:
    sqlite3 *db_ = nullptr;
    sqlite3_stmt *state_ = nullptr;
    std::unique_ptr<char, decltype(&free)>
        fileLoc_{nullptr, free}; // Smart pointer for automatic memory management

    int status_; // Status of the last SQLite operation
    QString trim(const QString &str);
};

#endif // STADIUMSDB_H
