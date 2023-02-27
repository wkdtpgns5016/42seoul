#include "Fwoosh.hpp"

Fwoosh::Fwoosh() : ASpell("Fwoosh", "fwooshed")
{

}
Fwoosh::Fwoosh(const Fwoosh& fwoosh)
{
    if (this == &fwoosh)
        return ;
    _name = fwoosh.getName();
    _effects = fwoosh.getEffects();
}

Fwoosh::~Fwoosh()
{

}

Fwoosh& Fwoosh::operator=(const Fwoosh& fwoosh)
{
    if (this == &fwoosh)
        return (*this);
    _name = fwoosh.getName();
    _effects = fwoosh.getEffects();
    return (*this);
    
}

Fwoosh* Fwoosh::clone()
{
    return (new Fwoosh());
}