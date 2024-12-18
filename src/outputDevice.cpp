#include "outputDevice.hpp"


void DummyOutputDevice::update(const std::unordered_map<std::string,Team> &teamMap){

    for(auto item : teamMap){
        std::println("DOD : Team Name = {0:} - Score = {1:}",item.second.getName(),item.second.getLocalScore().getPoints());
    }

}


