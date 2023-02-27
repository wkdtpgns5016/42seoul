#include "Warlock.hpp"

Warlock::Warlock() : _name(), _title()
{
    int i;
    for (i = 0; i < 10; i++)
        _spell[i] = 0;
    std::cout << _name << ": This looks like another boring day." << std::endl;
}

Warlock::~Warlock()
{
    for (int i = 0; i < 10; i++)
    {
        if (_spell[i] != 0)
            delete _spell[i];
        _spell[i] = 0;
    }
    std::cout << _name << ": My job here is done!" << std::endl;
}

Warlock::Warlock(const Warlock& warlock)
{
    int i;

    if (this == &warlock)
        return ;
    for (i = 0; i < 10; i++)
    {
        if (_spell[i] != 0)
            delete _spell[i];
    }
    for (i = 0; i < 10; i++)
        _spell[i] = warlock._spell[i];
    _name = warlock.getName();
    _title = warlock.getTitle();
    std::cout << _name << ": This looks like another boring day." << std::endl;
}

Warlock& Warlock::operator=(const Warlock& warlock)
{
    int i;

    if (this == &warlock)
        return (*this);
    for (i = 0; i < 10; i++)
    {
        if (_spell[i] != 0)
            delete _spell[i];
    }
    for (i = 0; i < 10; i++)
        _spell[i] = warlock._spell[i];
    _name = warlock.getName();
    _title = warlock.getTitle();
    return (*this);
}

Warlock::Warlock(const std::string& name, const std::string& title)
{
    int i;

    _name = name;
    _title = title;
    for (i = 0; i < 10; i++)
        _spell[i] = 0;
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

int Warlock::getSizeSpells()
{
    int i;
    for (i = 0; i < 10; i++)
    {
        if (_spell[i] == 0)
            break;
    }
    return (i);
}

int Warlock::getIndexSpells(const std::string& spell)
{
    int i;
    for (i = 0; i < 10; i++)
    {
        if (_spell[i] != 0)
        {
            if (spell.compare(_spell[i]->getName()) == 0)
                break;
        }
    }
    return (i);
}

void Warlock::learnSpell(ASpell *spell)
{
    int i = getSizeSpells();
    if (i >= 10)
        return ;
    _spell[i] = spell->clone();
}

void Warlock::forgetSpell(const std::string& spell)
{
    int i = getIndexSpells(spell);
    if (i >= 10)
        return ;
    delete _spell[i];
    _spell[i] = 0;
}

void Warlock::launchSpell(const std::string& spell, ATarget& target)
{
    int i = getIndexSpells(spell);
    if (i >= 10)
        return ;
    _spell[i]->launch(target);
}

int main()
{
    Warlock richard("Richard", "the Titled");

    Dummy bob;
    Fwoosh* fwoosh = new Fwoosh();

    richard.learnSpell(fwoosh);

    richard.introduce();
    richard.launchSpell("Fwoosh", bob);

    richard.forgetSpell("Fwoosh");
    richard.launchSpell("Fwoosh", bob);
}