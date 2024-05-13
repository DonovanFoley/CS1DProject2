#include "stadiumdb.h"
//hi
StadiumsDB::StadiumsDB(const char *dbfile)
{
    file_loc_ = strdup(dbfile);
}

StadiumsDB::StadiumsDB() {}

void StadiumsDB::set_file(const char* dbfile)
{
  file_loc_ = strdup(dbfile);
}

void StadiumsDB::set_file(const QString dbfile)
{
  file_loc_ = strdup(dbfile.toStdString().data());
}

int StadiumsDB::num_stadiums()
{
    prepare_statement("SELECT count() FROM stadium");
    status_ = sqlite3_step(state_);

    int num = sqlite3_column_int(state_, 0);

    finalize_statement();

    return num;
}

void StadiumsDB::populate_teams(Map &teams)
{
    teams.clear();
    prepare_statement("SELECT * FROM stadium"); //make table of all stadiums

    status_ = sqlite3_step(state_); //do until out of rows in table
    while (status_ != SQLITE_DONE) {
        QVector<Team>::reference ref = teams.insert(Team()); //insert new team
        modify_stadium_info(ref);                            //populate it with data
        status_ = sqlite3_step(state_);
    }

    finalize_statement();
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

void StadiumsDB::modify_stadium_info(Team &stadium)
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

void StadiumsDB::save_changes()
{
  std::cout << "Making Save!\n";
}

void StadiumsDB::prepare_statement(std::string statement)
{
    status_ = sqlite3_open(file_loc_, &db_);

    if (status_ != SQLITE_OK)
        std::cout << "Fatal Error Opening File! Unable to proceed!\n";

    status_ = sqlite3_prepare_v2(db_, statement.c_str(), -1, &state_, NULL);

    if (status_ != SQLITE_OK)
        std::cout << "Could Not Prepare Statement!\n";
}

void StadiumsDB::finalize_statement()
{
    while (status_ != SQLITE_DONE)
        status_ = sqlite3_step(state_);

    sqlite3_finalize(state_);
    sqlite3_close(db_);
}
