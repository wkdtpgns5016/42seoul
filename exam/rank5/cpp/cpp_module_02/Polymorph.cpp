#include "Polymorph.hpp"

Polymorph::Polymorph() : ASpell("Polymorph", "turned into a critter")
{

}

Polymorph::Polymorph(const Polymorph& polymorph)
{
    if (this == &polymorph)
        return ;
    _name = polymorph.getName();
    _effects = polymorph.getEffects();
}

Polymorph::~Polymorph()
{

}

Polymorph& Polymorph::operator=(const Polymorph& polymorph)
{
    if (this == &polymorph)
        return (*this);
    _name = polymorph.getName();
    _effects = polymorph.getEffects();
    return (*this);
}

Polymorph* Polymorph::clone()
{
    return (new Polymorph());
}