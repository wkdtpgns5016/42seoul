#include "Warlock.hpp"

Warlock::Warlock() : name(), title(), spellBook(new SpellBook())
{
    std::cout << name << ": This looks like another boring day." << std::endl;
}

Warlock::Warlock(const Warlock& warlock) : name(warlock.name), title(warlock.title), spellBook(new SpellBook())
{
    std::cout << name << ": This looks like another boring day." << std::endl;
}

Warlock& Warlock::operator=(const Warlock& warlock)
{
    this->name = warlock.name;
    this->title = warlock.title;
    this->spellBook = new SpellBook();
    return (*this);
}

Warlock::Warlock(const std::string& name, const std::string& title)
{
    this->name = name;
    this->title = title;
    this->spellBook = new SpellBook();
    std::cout << this->name << ": This looks like another boring day." << std::endl;
}

Warlock::~Warlock()
{
    delete spellBook;
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
    spellBook->learnSpell(spell);
}

void Warlock::forgetSpell(const std::string& spell)
{
    spellBook->forgetSpell(spell);
}

void Warlock::launchSpell(const std::string& spell, ATarget& target)
{
    ASpell* spells;
    spells = spellBook->createSpell(spell);
    if (spells)
    {
        spells->launch(target);
        delete spells;
    }
}