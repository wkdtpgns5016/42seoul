#include "Fwoosh.hpp"

Fwoosh::Fwoosh() : ASpell("Fwoosh", "fwooshed")
{

}

Fwoosh::Fwoosh(const Fwoosh& fwoosh) : ASpell(fwoosh.name, fwoosh.effects)
{

}

Fwoosh::~Fwoosh()
{

}

Fwoosh& Fwoosh::operator=(const Fwoosh& fwoosh)
{
    name = fwoosh.name;
    effects = fwoosh.effects;
    return (*this);
}


ASpell* Fwoosh::clone() const
{
    return (new Fwoosh());
}
