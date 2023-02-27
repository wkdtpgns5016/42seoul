#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator(const TargetGenerator& targetGenerator)
{
    if (this == & targetGenerator)
        return ;
    for (int i = 0; i < MAX_TARGET; i++)
    {
        if (_target[i] != 0)
            delete _target[i];
    }
    for (int i = 0; i < MAX_TARGET; i++)
        _target[i] = targetGenerator._target[i];
}
TargetGenerator& TargetGenerator::operator=(const TargetGenerator& targetGenerator)
{
    if (this == & targetGenerator)
        return (*this);
    for (int i = 0; i < MAX_TARGET; i++)
    {
        if (_target[i] != 0)
            delete _target[i];
    }
    for (int i = 0; i < MAX_TARGET; i++)
        _target[i] = targetGenerator._target[i];
    return (*this);
}

TargetGenerator::TargetGenerator() : _target()
{
    
}

TargetGenerator::~TargetGenerator()
{
    for (int i = 0; i < MAX_TARGET; i++)
    {
        if (_target[i] != 0)
            delete _target[i];
        _target[i] = 0;
    }
}

void TargetGenerator::learnTargetType(ATarget* target)
{
    int i = getSizeTargets();
    if (i >= MAX_TARGET)
        return ;
    _target[i] = target->clone();
}

void TargetGenerator::forgetTargetType(std::string const & target)
{
    int i = getIndexTargets(target);
    if (i >= MAX_TARGET)
        return ;
    delete _target[i];
    _target[i] = 0;
}

ATarget* TargetGenerator::createTarget(std::string const & target)
{
    int i = getIndexTargets(target);
    if (i >= MAX_TARGET)
        return 0;
    return (_target[i]->clone());
}

int TargetGenerator::getSizeTargets()
{
    int i;
    for (i = 0; i < MAX_TARGET; i++)
    {
        if (_target[i] == 0)
            break;
    }
    return (i);
}

int TargetGenerator::getIndexTargets(const std::string& spell)
{
    int i;
    for (i = 0; i < MAX_TARGET; i++)
    {
        if (_target[i] != 0)
        {
            if (spell.compare(_target[i]->getType()) == 0)
                break;
        }
    }
    return (i);
}