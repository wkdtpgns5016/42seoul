#ifndef FIREWALL_HPP
#define FIREWALL_HPP

#include "ASpell.hpp"

class Firewall : public ASpell
{
    public:
    Firewall();
    Firewall(const Firewall& fireWall);
    ~Firewall();
    Firewall& operator=(const Firewall& fireWall);

    ASpell* clone() const;
};

#endif