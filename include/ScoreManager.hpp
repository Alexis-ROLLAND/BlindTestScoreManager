#ifndef __SCORE_MANAGER_HPP__
#define __SCORE_MANAGER_HPP__

#include <unordered_map>
#include <string>
#include <print>

#include "Team.hpp"

class   ScoreManager{
    private:
        std::unordered_map<std::string,Team> TeamMap{};

    public:
        ScoreManager() = default;
        virtual ~ScoreManager() = default;

        auto    getNbTeams() {return this->TeamMap.size();};

        void    addTeam(const std::string &TeamName){this->TeamMap.insert({TeamName, Team{TeamName}});};

        uint16_t    getTeamScore(const std::string &TeamName){return this->TeamMap.at(TeamName).getLocalScore().getPoints();};
        void        incTeamScore(const std::string &TeamName, uint16_t Nb = 1){this->TeamMap.at(TeamName).getLocalScore().inc(Nb);};    

        void    listTeamNames();

};



#endif  /*  __SCORE_MANAGER_HPP__   */