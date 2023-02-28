#include "SpellBook.hpp"

SpellBook::SpellBook(const SpellBook& spell) : book(spell.book)
{

}

SpellBook& SpellBook::operator=(const SpellBook& spell) 
{
    book = spell.book;
    return (*this);
}


SpellBook::SpellBook() : book()
{

}

SpellBook::~SpellBook()
{

}

void SpellBook::learnSpell(ASpell* spell)
{
    book.insert(std::make_pair(spell->getName(), spell));
}

void SpellBook::forgetSpell(std::string const & spell)
{
    if (book.count(spell))
        book.erase(spell);
}

ASpell* SpellBook::createSpell(std::string const & spell)
{
    if (book.count(spell))
        return (book.find(spell)->second->clone());
    return (0);
}