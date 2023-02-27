#include "ASpell.hpp"

ASpell::ASpell() : _name(), _effects()
{

}

ASpell::ASpell(const ASpell& spell)
{
    if (this == &spell)
        return ;
    _name = spell._name;
    _effects = spell._effects;
}

ASpell::ASpell(const std::string& name, const std::string& effects)
{
    _name = name;
    _effects = effects;
}

ASpell::~ASpell()
{

}

ASpell& ASpell::operator=(const ASpell& spell)
{
    if (this == &spell)
        return (*this);
    _name = spell._name;
    _effects = spell._effects;
    return (*this);
}

const std::string& ASpell::getName() const
{
    return (_name);
}

const std::string& ASpell::getEffects() const
{
    return (_effects);
}

void ASpell::launch(const ATarget& target)
{
    target.getHitBySpell(*this);
}