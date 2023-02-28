#ifndef BRICKWALL_HPP
#define BRICKWALL_HPP

#include "ATarget.hpp"

class BrickWall : public ATarget
{
    public:
    BrickWall();
    BrickWall(const BrickWall& brickWall);
    ~BrickWall();
    BrickWall& operator=(const BrickWall& brickWall);
    ATarget* clone() const;
};

#endif