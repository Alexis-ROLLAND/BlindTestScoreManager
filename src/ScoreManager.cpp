#include "ScoreManager.hpp"



void    ScoreManager::listTeamNames(){
    for(auto team : this->TeamMap){
        std::println("{}",team.second.getName());
    }
}
