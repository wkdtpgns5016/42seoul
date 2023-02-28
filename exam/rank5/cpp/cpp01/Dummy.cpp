#include "Dummy.hpp"

Dummy::Dummy() : ATarget("Target Practice Dummy")
{

}

Dummy::Dummy(const Dummy& dummy) : ATarget(dummy.type)
{

}

Dummy::~Dummy()
{

}

Dummy& Dummy::operator=(const Dummy& dummy)
{
    type = dummy.type;
    return (*this);
}

ATarget* Dummy::clone() const
{
    return (new Dummy());
}
