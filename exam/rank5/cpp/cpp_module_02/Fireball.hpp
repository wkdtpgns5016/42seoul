#ifndef FIREBALL_HPP
#define FIREBALL_HPP

#include "ASpell.hpp"

class Fireball : public ASpell
{
    public:
    Fireball();
    Fireball(const Fireball& fireball);
    ~Fireball();
    Fireball& operator=(const Fireball& fireball);
    Fireball* clone();
};

#endif