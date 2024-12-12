#ifndef __TEAM_HPP__
#define __TEAM_HPP__

#include <string>

#include "Score.hpp"

class Team{
    private:
        std::string Name{};
        Score   TeamScore{};

    public:
        Team() = default;
        Team(const std::string &Name):Name{Name}{};
        virtual ~Team() = default;

        std::string getName(){return this->Name;};
        void        setName(const std::string &Name){this->Name = Name;};

        Score&  getLocalScore() {return this->TeamScore;};


};



#endif  /*  __TEAM_HPP__    */

