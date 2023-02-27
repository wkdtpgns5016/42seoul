#ifndef BRICKWALL_HPP
#define BRICKWALL_HPP

#include "ATarget.hpp"

class BrickWall : public ATarget
{
    public:
    BrickWall();
    BrickWall(const BrickWall& brickwall);
    ~BrickWall();
    BrickWall& operator=(const BrickWall& brickwall);
    BrickWall* clone();
};

#endif