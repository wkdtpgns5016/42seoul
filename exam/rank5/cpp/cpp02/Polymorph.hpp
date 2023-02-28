#ifndef POLYMORPH_HPP
#define POLYMORPH_HPP

#include "ASpell.hpp"

class Polymorph : public ASpell
{
    public:
    Polymorph();
    Polymorph(const Polymorph& polyMorph);
    ~Polymorph();
    Polymorph& operator=(const Polymorph& polyMorph);
    ASpell* clone() const;
};

#endif