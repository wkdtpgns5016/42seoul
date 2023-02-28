#ifndef DUMMY_HPP
#define DUMMY_HPP

#include "ATarget.hpp"

class Dummy : public ATarget
{
    public:
    Dummy();
    Dummy(const Dummy& dummy);
    ~Dummy();
    Dummy& operator=(const Dummy& dummy);

    ATarget* clone() const;
};

#endif