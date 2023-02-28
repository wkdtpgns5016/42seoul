#include "Warlock.hpp"

Warlock::Warlock() : name(), title(), spells()
{
    std::cout << name << ": This looks like another boring day." << std::endl;
}

Warlock::Warlock(const Warlock& warlock) : name(warlock.name), title(warlock.title), spells()
{
    std::cout << name << ": This looks like another boring day." << std::endl;
}

Warlock& Warlock::operator=(const Warlock& warlock)
{
    this->name = warlock.name;
    this->title = warlock.title;
    std::cout << name << ": My job here is done!" << std::endl;
    return (*this);
}

Warlock::Warlock(const std::string& name, const std::string& title)
{
    this->name = name;
    this->title = title;
    std::cout << this->name << ": This looks like another boring day." << std::endl;
}

Warlock::~Warlock()
{
    std::cout << name << ": My job here is done!" << std::endl;
}

const std::string& Warlock::getName() const
{
    return (name);
}

const std::string& Warlock::getTitle() const
{
    return (title);
}

void Warlock::setTitle(const std::string& title)
{
    this->title = title;
}

void Warlock::introduce() const
{
    std::cout << name << ": I am " << name << ", " << title << "!" << std::endl;
}

void Warlock::learnSpell(ASpell* spell)
{
    spells.insert(std::make_pair(spell->getName(), spell));
}

void Warlock::forgetSpell(const std::string& spell)
{
    if (spells.count(spell))
        spells.erase(spell);
}

void Warlock::launchSpell(const std::string& spell, ATarget& target)
{
    if (spells.count(spell))
        spells.find(spell)->second->launch(target);
}