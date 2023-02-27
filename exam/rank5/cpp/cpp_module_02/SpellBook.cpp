#include "SpellBook.hpp"

SpellBook::SpellBook(const SpellBook& spellbook)
{
    if (this == & spellbook)
        return ;
    for (int i = 0; i < MAX_SPELL; i++)
    {
        if (_spell[i] != 0)
            delete _spell[i];
    }
    for (int i = 0; i < MAX_SPELL; i++)
        _spell[i] = spellbook._spell[i];
}
SpellBook& SpellBook::operator=(const SpellBook& spellbook)
{
    if (this == & spellbook)
        return (*this);
    for (int i = 0; i < MAX_SPELL; i++)
    {
        if (_spell[i] != 0)
            delete _spell[i];
    }
    for (int i = 0; i < MAX_SPELL; i++)
        _spell[i] = spellbook._spell[i];
    return (*this);
}

SpellBook::SpellBook() : _spell()
{
    
}

SpellBook::~SpellBook()
{
    for (int i = 0; i < MAX_SPELL; i++)
    {
        if (_spell[i] != 0)
            delete _spell[i];
        _spell[i] = 0;
    }
}

void SpellBook::learnSpell(ASpell* spell)
{
    int i = getSizeSpells();
    if (i >= MAX_SPELL)
        return ;
    _spell[i] = spell->clone();
}

void SpellBook::forgetSpell(std::string const & spell)
{
    int i = getIndexSpells(spell);
    if (i >= MAX_SPELL)
        return ;
    delete _spell[i];
    _spell[i] = 0;
}

ASpell* SpellBook::createSpell(std::string const & spell)
{
    int i = getIndexSpells(spell);
    if (i >= MAX_SPELL)
        return 0;
    return (_spell[i]->clone());
}

int SpellBook::getSizeSpells()
{
    int i;
    for (i = 0; i < MAX_SPELL; i++)
    {
        if (_spell[i] == 0)
            break;
    }
    return (i);
}

int SpellBook::getIndexSpells(const std::string& spell)
{
    int i;
    for (i = 0; i < MAX_SPELL; i++)
    {
        if (_spell[i] != 0)
        {
            if (spell.compare(_spell[i]->getName()) == 0)
                break;
        }
    }
    return (i);
}