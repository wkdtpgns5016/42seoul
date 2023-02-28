#ifndef TARGETGENERATOR_HPP
#define TARGETGENERATOR_HPP

#include <iostream>
#include <map>
#include "ATarget.hpp"

class TargetGenerator
{
    private:
    std::map<std::string, ATarget*> generator;

    TargetGenerator(const TargetGenerator& gen);
    TargetGenerator& operator=(const TargetGenerator& gen);
    
    public:
    TargetGenerator();
    ~TargetGenerator();

    void learnTargetType(ATarget* target);
    void forgetTargetType(std::string const & target);
    ATarget* createTarget(std::string const & target);
};

#endif