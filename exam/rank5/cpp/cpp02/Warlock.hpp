#ifndef WARLOCK_HPP
#define WARLOCK_HPP

#include <iostream>
#include "ASpell.hpp"
#include "ATarget.hpp"
#include "SpellBook.hpp"

class Warlock
{
    private:
    std::string name;
    std::string title;
    SpellBook*  spellBook;
    
    Warlock();
    Warlock(const Warlock& warlock);
    Warlock& operator=(const Warlock& warlock);

    public:
    Warlock(const std::string& name, const std::string& title);
    ~Warlock();

    const std::string& getName() const;
    const std::string& getTitle() const;
    void setTitle(const std::string& name);
    void introduce() const;

    void learnSpell(ASpell* spell);
    void forgetSpell(const std::string& spell);
    void launchSpell(const std::string& spell, ATarget& target);
};

#endif