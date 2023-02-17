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
#include <set>

int		main(void)
{
	std::set<int> s;
	s.insert(3);
	s.insert(4);
	s.insert(5);
	s.insert(6);

	std::cout << (*(s.begin())) << std::endl;
	
	return (0);
}
