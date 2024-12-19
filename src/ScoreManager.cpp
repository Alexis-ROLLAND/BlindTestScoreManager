#include "ScoreManager.hpp"



void    ScoreManager::listTeamNames()noexcept{
    for(auto team : this->TeamMap){
        std::println(std::clog,"{}",team.second.getName());
    }
}
