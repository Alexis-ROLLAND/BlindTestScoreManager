#ifndef __SCORE_HPP__
#define __SCORE_HPP__

#include <cstdint>

class Score
{
private:
    uint16_t    Points{0};

    void setPoints(uint16_t Nb){this->Points = Nb;};
    
public:
    Score() = default;
    explicit Score(uint16_t initialPoints):Points{initialPoints}{};
    virtual ~Score() = default;

    uint16_t getPoints(){return this->Points;};

    void    reset(){this->setPoints(0);};
    void    set(uint16_t Nb){this->setPoints(Nb);};

    void    inc(uint16_t Value = 1){this->setPoints(this->getPoints() + Value);};
    void    dec(uint16_t Value = 1);

};




#endif  /*  __SCORE_HPP__   */