#include "vector.hpp"
#include <vector>
#include <stack>
#include <iostream>

int main()
{
    unsigned int i;
    int myints[] = {0, 1, 2, 3};
    int myints2[] = {4, 5, 6, 7};
    ft::vector<int> fifth(myints, myints + sizeof(myints) / sizeof(int));
    std::cout << "\n" << fifth.size() << " " << fifth.capacity() << std::endl;

    fifth.push_back(4);
    fifth.push_back(5);
    fifth.push_back(6);
    fifth.push_back(7);
    fifth.push_back(8);
    ft::vector<int>::iterator it = fifth.begin();
    for (; it != fifth.end(); it++)
    {
        std::cout<< *it << " ";
    }
    std::cout << "\n" << fifth.size() << " " << fifth.capacity() << std::endl;



    fifth.erase(fifth.begin(), fifth.begin() + 3);
    it = fifth.begin();
    for (; it != fifth.end(); it++)
    {
        std::cout<< *it << " ";
    }
    std::cout << "\n" << fifth.size() << " " << fifth.capacity() << std::endl;
    return 0;
}
