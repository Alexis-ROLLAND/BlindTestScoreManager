#include "Score.hpp"


void    Score::dec(uint16_t Value){
    if (Value > this->getPoints()) this->setPoints(0);
    else (this->setPoints(this->getPoints() - Value));
}

