#include "BrickWall.hpp"

BrickWall::BrickWall() : ATarget("Inconspicuous Red-brick Wall")
{

}

BrickWall::BrickWall(const BrickWall& brickWall) : ATarget(brickWall.getType())
{

}

BrickWall::~BrickWall()
{

}

BrickWall& BrickWall::operator=(const BrickWall& brickWall)
{
    type = brickWall.getType();
    return (*this);
}

ATarget* BrickWall::clone() const
{
    return (new BrickWall());
}
