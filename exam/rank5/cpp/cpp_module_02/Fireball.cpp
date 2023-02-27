#include "Fireball.hpp"

Fireball::Fireball() : ASpell("Fireball", "burnt to a crisp")
{

}

Fireball::Fireball(const Fireball& fireball)
{
    if (this == &fireball)
        return ;
    _name = fireball.getName();
    _effects = fireball.getEffects();
}

Fireball::~Fireball()
{

}

Fireball& Fireball::operator=(const Fireball& fireball)
{
    if (this == &fireball)
        return (*this);
    _name = fireball.getName();
    _effects = fireball.getEffects();
    return (*this);
}

Fireball* Fireball::clone()
{
    return (new Fireball());
}