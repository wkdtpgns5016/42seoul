#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator() : generator()
{

}

TargetGenerator::TargetGenerator(const TargetGenerator& gen)
{
    generator.insert(gen.generator.begin(), gen.generator.end());
}

TargetGenerator::~TargetGenerator()
{

}

TargetGenerator& TargetGenerator::operator=(const TargetGenerator& gen)
{
    generator.insert(gen.generator.begin(), gen.generator.end());
    return (*this);
}


void TargetGenerator::learnTargetType(ATarget* target)
{
    generator.insert(std::make_pair(target->getType(), target));
}

void TargetGenerator::forgetTargetType(std::string const & target)
{
    if (generator.count(target))
        generator.erase(target);
}

ATarget* TargetGenerator::createTarget(std::string const & target)
{
    if (generator.count(target))
        return (generator.find(target)->second->clone());
    return (0);
}
