#include "Dummy.hpp"

Dummy::Dummy() : ATarget("Target Practice Dummy")
{

}

Dummy::Dummy(const Dummy& dummy)
{
    if (this == &dummy)
        return ;
    _type = dummy.getType();
}

Dummy::~Dummy()
{

}

Dummy& Dummy::operator=(const Dummy& dummy)
{
    if (this == &dummy)
        return (*this);
    _type = dummy.getType();
    return (*this);
}

Dummy* Dummy::clone()
{
    return (new Dummy());
}