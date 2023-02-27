#ifndef POLYMORPH
#define POLYMORPH

#include "ASpell.hpp"

class Polymorph : public ASpell
{
    public:
    Polymorph();
    Polymorph(const Polymorph& polymorph);
    ~Polymorph();
    Polymorph& operator=(const Polymorph& polymorph);
    Polymorph* clone();
};

#endif