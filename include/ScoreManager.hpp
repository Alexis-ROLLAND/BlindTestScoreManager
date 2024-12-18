#ifndef __SCORE_MANAGER_HPP__
#define __SCORE_MANAGER_HPP__

#include <unordered_map>
#include <string>
#include <print>

#include "outputDevice.hpp"
#include "Team.hpp"

class   ScoreManager{
    private:
        std::unordered_map<std::string,Team> TeamMap{};

        OutputDevice    &Screen;    

    public:
        ScoreManager() = delete;
        virtual ~ScoreManager() = default;

        ScoreManager(OutputDevice &od):Screen{od}{};

        auto    getNbTeams() {return this->TeamMap.size();};

        void    addTeam(const std::string &TeamName){this->TeamMap.insert({TeamName, Team{TeamName}});this->updateScreen();};
        void    removeTeam(const std::string &TeamName){this->TeamMap.erase(TeamName);this->updateScreen();};

        uint16_t    getTeamScore(const std::string &TeamName){return this->TeamMap.at(TeamName).getLocalScore().getPoints();};
        void        incTeamScore(const std::string &TeamName, uint16_t Nb = 1){this->TeamMap.at(TeamName).getLocalScore().inc(Nb);this->updateScreen();};    
        void        decTeamScore(const std::string &TeamName, uint16_t Nb = 1){this->TeamMap.at(TeamName).getLocalScore().dec(Nb);this->updateScreen();};   

        void        updateScreen() {this->Screen.update(this->TeamMap);};

        void    listTeamNames();

};



#endif  /*  __SCORE_MANAGER_HPP__   */