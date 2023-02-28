#include "ASpell.hpp"

ASpell::ASpell() : name(), effects()
{

}

ASpell::ASpell(const ASpell& spell) : name(spell.name), effects(spell.effects)
{

}

ASpell::ASpell(const std::string& _name, const std::string& _effects) : name(_name), effects(_effects)
{

}

ASpell::~ASpell()
{

}

ASpell& ASpell::operator=(const ASpell& spell)
{
    name = spell.name;
    effects = spell.effects;
    return (*this);
}

const std::string& ASpell::getName() const
{
    return (name);
}

const std::string& ASpell::getEffects() const
{
    return (effects);
}

void ASpell::launch(const ATarget& target)
{
    target.getHitBySpell(*this);
}