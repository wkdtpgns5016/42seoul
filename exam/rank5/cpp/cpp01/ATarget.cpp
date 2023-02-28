#include "ATarget.hpp"

ATarget::ATarget() : type()
{

}

ATarget::ATarget(const ATarget& target) : type(target.type)
{

}

ATarget::ATarget(const std::string& _type) : type(_type)
{

}

ATarget::~ATarget()
{

}

ATarget& ATarget::operator=(const ATarget& target)
{
    type = target.type;
    return (*this);
}

void ATarget::getHitBySpell(const ASpell& spell) const
{
    std::cout << type << " has been " << spell.getEffects() << "!" << std::endl;
}
