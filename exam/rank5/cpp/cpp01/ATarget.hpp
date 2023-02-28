#ifndef ATARGET_HPP
#define ATARGET_HPP

#include <iostream>
#include "ASpell.hpp"

class ASpell;
class ATarget
{
    protected:
    std::string type;

    public:
    ATarget();
    ATarget(const ATarget& target);
    ATarget(const std::string& _type);
    virtual ~ATarget();
    ATarget& operator=(const ATarget& target);

    virtual ATarget* clone() const = 0;
    void getHitBySpell(const ASpell& spell) const;
};

#endif