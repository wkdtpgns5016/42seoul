#include "Warlock.hpp"

Warlock::Warlock() : _name(), _title()
{
    std::cout << _name << ": This looks like another boring day." << std::endl;
}

Warlock::~Warlock()
{
    std::cout << _name << ": My job here is done!" << std::endl;
}

Warlock::Warlock(const Warlock& warlock)
{
    if (this == &warlock)
        return ;
    _name = warlock.getName();
    _title = warlock.getTitle();
    std::cout << _name << ": This looks like another boring day." << std::endl;
}

Warlock& Warlock::operator=(const Warlock& warlock)
{
    if (this == &warlock)
        return (*this);
    _name = warlock.getName();
    _title = warlock.getTitle();
    return (*this);
}

Warlock::Warlock(const std::string& name, const std::string& title)
{
    _name = name;
    _title = title;
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

int main()
{
    // Warlock bob;                            //Does not compile
    // Warlock bob("Bob", "the magnificent");  //Compiles
    // Warlock jim("Jim", "the nauseating");   //Compiles
    // bob = jim;                              //Does not compile
    // Warlock jack(jim);                      //Does not compile
    Warlock const richard("Richard", "Mistress of Magma");
    richard.introduce();
    std::cout << richard.getName() << " - " << richard.getTitle() << std::endl;

    Warlock* jack = new Warlock("Jack", "the Long");
    jack->introduce();
    jack->setTitle("the Mighty");
    jack->introduce();

    delete jack;

    return (0);
}