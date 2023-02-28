#include "Firewall.hpp"

Firewall::Firewall() : ASpell("Firwall", "burnt to a crisp")
{

}

Firewall::Firewall(const Firewall& fireWall) : ASpell(fireWall.getName(), fireWall.getEffects())
{

}

Firewall::~Firewall()
{

}

Firewall& Firewall::operator=(const Firewall& fireWall)
{
    name = fireWall.getName();
    effects = fireWall.getEffects();
    return (*this);
}


ASpell* Firewall::clone() const
{
    return (new Firewall());
}
