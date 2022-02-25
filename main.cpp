#include <iostream>
#include "nlohmann/json.hpp"
#include <fstream>
#include <vector>
#include <map>

//структура для создания файла
struct MovieAdd
{
    std::string movie_title = "Dead end";
    std::string genre = "horror";
    int date_of_creation = 2003;
    std::string studio_name = "France";

    std::map<std::string, std::vector<std::string>> team {
            {"autors", {{"Jean-Baptiste Andrea"}, {"Fabrice Canepa"}}},
            {"directors", {{"Jean-Baptiste Andrea"}, {"Fabrice Canepa"}}},
            {"producers", {{"Sonya Shillito"}, {"Gabriella Stollenwerk"}, {"Cecile Telerman"}}},
            {"actors", {{"Alexandra Holden"},
                              {"Ray Wise"},
                              {"Lin Shay"},
                              {"Mick Kane"},
                              {"Amber Smith"},
                              {"Billy Asher"},
                              {"Karen S. Gregan"},
                              {"Sharon Madden"},
                              {"Steve Valentine"},
                              {"Jimmy F. Skaggs"}}}
    };

};


void add()
{
    std::ofstream file("movie.json");
    MovieAdd movie;
    nlohmann::json list;

    list["movie_title"] = movie.movie_title;
    list["genre"] = movie.genre;
    list["date_of_creation"] = movie.date_of_creation;
    list["studio_name"] = movie.studio_name;

    for(auto it = movie.team.begin(); it != movie.team.end(); ++it)
    {
        for(int j = 0; j < it->second.size(); ++j)
        {
            list[it->first].push_back(it->second[j]);
        }
    }

    file << list;
    file.close();
}

int main() {
    add();
    return 0;
}
