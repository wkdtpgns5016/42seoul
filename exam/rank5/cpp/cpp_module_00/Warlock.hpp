#ifndef WARLOCK_HPP
#define WARLOCK_HPP

#include <iostream>

class Warlock
{
    private:
    std::string _name;
    std::string _title;

    Warlock();
    Warlock(const Warlock& warlock);
    Warlock& operator=(const Warlock& warlock);

    public:
    Warlock(const std::string& name, const std::string& title);
    ~Warlock();
    const std::string& getName() const;
    const std::string& getTitle() const;
    void setTitle(std::string title);
    void introduce() const;
};


#endif