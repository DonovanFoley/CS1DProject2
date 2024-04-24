#ifndef DBINTERFACE_H
#define DBINTERFACE_H

#include "sqlite3.h"
#include "team.h"
#include "map.h"
#include <iostream>
#include <vector>

class StadiumsDB 
{
  public:
    StadiumsDB(const char * dbfile);
    StadiumsDB() = delete;

    int num_stadiums();

    void populate_teams(Map& teams);
    
    void modify_stadium_info(Team&);

  protected:
    void prepare_statement(std::string);
    void finalize_statement();

  private:
    sqlite3* db_;
    sqlite3_stmt* state_;
    int status_;

    char * file_loc_;
};

#endif
