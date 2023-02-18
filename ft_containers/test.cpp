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
#include "stack.hpp"

int		main(void)
{
	ft::vector<int>	ctnr;

	ctnr.push_back(21);
	ctnr.push_back(42);
	ctnr.push_back(1337);
	ctnr.push_back(19);
	ctnr.push_back(0);
	ctnr.push_back(183792);

	for (ft::vector<int>::iterator it = ctnr.begin(); it != ctnr.end(); it++)
	{
		std::cout << *it << " ";
	}
	ft::stack<int> stck(ctnr);
	std::cout << "empty: " << ctnr.empty() << std::endl;
	std::cout << std::endl << "Content was:" << std::endl;
		while (ctnr.size() != 0) {
			std::cout << "- " << ctnr.back() << std::endl;
			ctnr.pop_back();
		}
	std::cout << "empty: " << stck.empty() << std::endl;
	std::cout << "size: " << stck.size() << std::endl;

	// stck.push(1);
	// stck.push(2);
	// stck.push(3);
	// stck.push(4);
	// stck.push(5);
	// stck.push(6);

	std::cout << "Added some elements" << std::endl;

	std::cout << "empty: " << stck.empty() << std::endl;
	std::cout << std::endl << "Content was:" << std::endl;
		while (stck.size() != 0) {
			std::cout << "- " << stck.top() << std::endl;
			stck.pop();
		}
	return (0);
}
