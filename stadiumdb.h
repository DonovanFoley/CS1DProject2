#ifndef DBINTERFACE_H
#define DBINTERFACE_H

#include "graph.h"
#include "map.h"
#include "sqlite3.h"
#include "team.h"

#include <iostream>
#include <sstream>
#include <vector>
//hi
class StadiumsDB
{
public:
    StadiumsDB(const char *dbfile);
    StadiumsDB();

    void set_file(const char *dbfile);
    void set_file(const QString dbfile);

    int num_stadiums();

    void populate_teams(Map &);
    void populate_souvenirs(Map &);

    void modify_stadium_info(Team &);

    Graph make_graph(const Map &);

    void update_team_info(Team *team);
    void update_souvenirs(Team *team);

    void save_changes();

protected:
    void prepare_statement(std::string);
    void finalize_statement();

private:
    sqlite3 *db_;
    sqlite3_stmt *state_;
    int status_;

    char *file_loc_;

    std::map<int, std::stringstream> update_statements;

    std::map<int, std::vector<std::stringstream> > update_souv;
};

#endif
