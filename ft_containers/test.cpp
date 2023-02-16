#include "vector.hpp"
#include <vector>
#include <stack>
#include <iostream>
#include <type_traits>
#include "type_traits.hpp"
#include "tree.hpp"
#include "utility.hpp"
#include <utility>
#include <map>
#include "map.hpp"
#include <vector>
#include <memory>
#include "iterator.hpp"
#include "utility.hpp"
#include "type_traits.hpp"
#include "tree.hpp"
#include <memory>
#include <exception>
#include <algorithm>
#include <map>


void test()
{

	ft::map<int, int> mp;

    mp[0] = 0;
    mp[1] = 1;
    mp[2] = 2;
    mp[3] = 3;
    mp[4] = 4;
    mp[5] = 5;

    mp.erase(mp.begin(), mp.end());
}

int		main(void)
{
    test();
	return (0);
}
