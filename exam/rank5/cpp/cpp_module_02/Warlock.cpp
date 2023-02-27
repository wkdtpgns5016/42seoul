#include "Warlock.hpp"

Warlock::Warlock() : _name(), _title(), _spell(new SpellBook())
{
    std::cout << _name << ": This looks like another boring day." << std::endl;
}

Warlock::~Warlock()
{
    delete _spell;
    std::cout << _name << ": My job here is done!" << std::endl;
}

Warlock::Warlock(const Warlock& warlock)
{
    if (this == &warlock)
        return ;
    if (_spell != 0)
        delete _spell;
    _name = warlock._name;
    _title = warlock._title;
    _spell = warlock._spell;
    std::cout << _name << ": This looks like another boring day." << std::endl;
}

Warlock& Warlock::operator=(const Warlock& warlock)
{
    if (this == &warlock)
        return (*this);
    if (_spell != 0)
        delete _spell;
    _name = warlock._name;
    _title = warlock._title;
    _spell = warlock._spell;
    return (*this);
}

Warlock::Warlock(const std::string& name, const std::string& title)
 : _name(name), _title(title), _spell(new SpellBook())
{
    std::cout << _name << ": This looks like another boring day." << std::endl;
}

const std::string& Warlock::getName() const
{
    return (_name);
}

const std::string& Warlock::getTitle() const
{
    return (_title);
}

void Warlock::setTitle(std::string title)
{
    _title = title;
}

void Warlock::introduce() const
{
    std::cout << _name << ": I am " << _name << ", " << _title << "!" << std::endl;
}

void Warlock::learnSpell(ASpell *spell)
{
    _spell->learnSpell(spell);
}

void Warlock::forgetSpell(const std::string& spell)
{
    _spell->forgetSpell(spell);
}

void Warlock::launchSpell(const std::string& spell, ATarget& target)
{
    ASpell* launch;

    launch = _spell->createSpell(spell);
    if (launch == 0)
        return ;
    launch->launch(target);
    delete launch;
}
