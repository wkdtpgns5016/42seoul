#include "vector.hpp"
#include <vector>
#include <iostream>

int main()
{
    unsigned int i;
    int myints[] = {16, 2, 77, 29};
    ft::vector<int> fifth(myints, myints + sizeof(myints) / sizeof(int));
    ft::vector<int>::iterator it = fifth.begin();
    it += 3;
    std::cout << *it << std::endl;
    return 0;
}
