#include "BrickWall.hpp"

BrickWall::BrickWall() : ATarget("Inconspicuous Red-brick Wall")
{

}

BrickWall::BrickWall(const BrickWall& brickwall)
{
    if (this == &brickwall)
        return ;
    _type = brickwall.getType();
}

BrickWall::~BrickWall()
{

}

BrickWall& BrickWall::operator=(const BrickWall& brickwall)
{
    if (this == &brickwall)
        return (*this);
    _type = brickwall.getType();
    return (*this);
}

BrickWall* BrickWall::clone()
{
    return (new BrickWall());
}