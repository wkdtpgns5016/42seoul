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

void show_pair(ft::pair<int, std::string> p)
{
	std::cout << p._first << " " << p._second << std::endl;
}

int		main(void)
{
	ft::pair<int, ft::pair<int,std::string> > a;
	ft::pair<int, std::string> p(8, "8a");
	ft::pair<int, std::string> p2(18, "18a");
	ft::pair<int, std::string> p3(5, "5a");
	ft::pair<int, std::string> p4(15, "15a");
	ft::pair<int, std::string> p5(17, "17a");
	ft::pair<int, std::string> p6(25, "25a");
	ft::pair<int, std::string> p7(40, "40a");
	ft::pair<int, std::string> p8(80, "80a");
	ft::rb_tree<int, ft::pair<int, std::string> > t;

	t.insert_node(p);
	t.insert_node(p2);
	t.insert_node(p3);
	t.insert_node(p4);
	t.insert_node(p5);
	t.insert_node(p6);
	t.insert_node(p7);
	t.insert_node(p8);

	std::map<char,int> mymap;

	mymap['b'] = 100;
	mymap['a'] = 200;

	// show content:
	std::map<char,int>::iterator it = mymap.begin();
	std::map<char,int>::iterator it2 = mymap.end();



	while (it != it2)
	{
		--it2; 
    	std::cout << it2->first << " => " << it2->second << '\n';
		if (it == it2)
			std::cout << &(*it) << " => " <<&(*it2) << '\n';
	}
	return (0);
}
