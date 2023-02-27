#ifndef TARGETGENERATOR_HPP
#define TARGETGENERATOR_HPP

#include "BrickWall.hpp"
#include <iostream>
#define MAX_TARGET 10

class TargetGenerator
{
    private:
    ATarget* _target[MAX_TARGET];

    TargetGenerator(const TargetGenerator& targetGenerator);
    TargetGenerator& operator=(const TargetGenerator& targetGenerator);
    int getSizeTargets();
    int getIndexTargets(const std::string& type);

    public:
    TargetGenerator();
    ~TargetGenerator();

    void learnTargetType(ATarget* target);
    void forgetTargetType(std::string const & type);
    ATarget* createTarget(std::string const & type);
};

#endif