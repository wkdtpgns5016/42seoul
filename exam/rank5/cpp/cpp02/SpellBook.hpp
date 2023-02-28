#ifndef SPELLBOOK_HPP
#define SPELLBOOK_HPP

#include "ASpell.hpp"
#include <iostream>
#include <map>

class SpellBook
{
    private:
    std::map<std::string, ASpell*> book;

    SpellBook(const SpellBook& spell);
    SpellBook& operator=(const SpellBook& spell);

    public:
    SpellBook();
    ~SpellBook();
    void learnSpell(ASpell* spell);
    void forgetSpell(std::string const & spell);
    ASpell* createSpell(std::string const & spell);
};

#endif