#include "Polymorph.hpp"

Polymorph::Polymorph() : ASpell("Polymorph", "turned into a critter")
{

}

Polymorph::Polymorph(const Polymorph& polyMorph) : ASpell(polyMorph.getName(), polyMorph.getEffects())
{

}

Polymorph::~Polymorph()
{

}

Polymorph& Polymorph::operator=(const Polymorph& polyMorph)
{
    name = polyMorph.getName();
    effects = polyMorph.getEffects();
    return (*this);
}

ASpell* Polymorph::clone() const
{
    return (new Polymorph());
}
