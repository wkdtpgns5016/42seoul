#ifndef WARLOCK_HPP
#define WARLOCK_HPP

#include <iostream>
#include "SpellBook.hpp"

class Warlock
{
    private:
    std::string _name;
    std::string _title;
    SpellBook   *_spell;

    Warlock();
    Warlock(const Warlock& warlock);
    Warlock& operator=(const Warlock& warlock);
    int getSizeSpells();
    int getIndexSpells(const std::string& spell);

    public:
    Warlock(const std::string& name, const std::string& title);
    ~Warlock();
    const std::string& getName() const;
    const std::string& getTitle() const;
    void setTitle(std::string title);
    void introduce() const;
    void learnSpell(ASpell *spell);
    void forgetSpell(const std::string& spell);
    void launchSpell(const std::string& spell, ATarget& target);
};


#endif