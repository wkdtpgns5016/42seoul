#ifndef SPELLBOOK_HPP
#define SPELLBOOK_HPP

#include <iostream>
#include "ASpell.hpp"
#include "Fireball.hpp"
#include "Polymorph.hpp"

#define MAX_SPELL 10

class SpellBook
{
    private:
    ASpell* _spell[MAX_SPELL];

    SpellBook(const SpellBook& spellbook);
    SpellBook& operator=(const SpellBook& spellbook);
    int getSizeSpells();
    int getIndexSpells(const std::string& spell);

    public:
    SpellBook();
    ~SpellBook();
    void learnSpell(ASpell* spell);
    void forgetSpell(std::string const & spell);
    ASpell* createSpell(std::string const & spell);
};

#endif