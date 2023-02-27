#include "ATarget.hpp"

ATarget::ATarget() :_type()
{

}

ATarget::ATarget(const ATarget& target)
{
    if (this == &target)
        return ;
    _type = target._type;
}

ATarget::ATarget(const std::string& type)
{
    _type = type;
}

ATarget::~ATarget()
{

}

ATarget& ATarget::operator=(const ATarget& target)
{
    if (this == &target)
        return (*this);
    _type = target._type;
    return (*this);
}

const std::string& ATarget::getType() const
{
    return (_type);
}

void ATarget::getHitBySpell(const ASpell& spell) const
{
    std::cout << _type << " has been " << spell.getEffects() << std::endl;
}