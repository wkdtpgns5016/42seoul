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

int		main(void)
{
	ft::map<int, char> m;
	std::map<int, char> m2;

	std::cout << m.max_size() << "\n" << m2.max_size() << std::endl;
	std::cout << (UINTPTR_MAX) <<std::endl;
	
	return (0);
}
