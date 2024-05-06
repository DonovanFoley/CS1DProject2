#ifndef DBINTERFACE_H
#define DBINTERFACE_H

#include "map.h"
#include "sqlite3.h"
#include "team.h"
#include "graph.h"

#include <iostream>
#include <sstream>
#include <vector>
//hi
class StadiumsDB
{
public:
    StadiumsDB(const char* dbfile);
    StadiumsDB();

    void set_file(const char* dbfile);
    void set_file(const QString dbfile);

    int num_stadiums();

    void populate_teams(Map&);
    void populate_souvenirs(Map&);

    void modify_stadium_info(Team&);

    Graph make_graph(const Map&);

protected:
    void prepare_statement(std::string);
    void finalize_statement();

private:
    sqlite3 *db_;
    sqlite3_stmt *state_;
    int status_;

    char *file_loc_;
};

#endif
