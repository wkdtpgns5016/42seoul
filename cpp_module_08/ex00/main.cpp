#include <easyfind.hpp>
#include <vector>     // std::vector
#include <list>
#include <deque>

int main() 
{
	int myints[] = {10, 20, 30, 40};

	// using std::find with vector and iterator:
	std::vector<int> myvector(myints, myints + 4);
	std::vector<int>::iterator vectorIter;

	vectorIter = easyfind(myvector, 30);
	if (vectorIter != myvector.end())
		std::cout << "Element found in myvector: " << *vectorIter << '\n';
	else
		std::cout << "Element not found in myvector\n";

	std::cout << "========================================" << std::endl;

	std::list<int> mylist(10);
	for (int i = 0; i < 10; ++i)
    	mylist.push_back(i);
	std::list<int>::iterator listIter;

	listIter = easyfind(mylist, 20);
	if (listIter != mylist.end())
		std::cout << "Element found in mylist: " << *listIter << '\n';
	else
		std::cout << "Element not found in mylist\n";

	std::cout << "========================================" << std::endl;

	std::deque<int> mydeque(10);
	for (int i = 0; i < 10; ++i)
    	mydeque.push_back(i);
	std::deque<int>::iterator dequeIter;

	dequeIter = easyfind(mydeque, 5);
	if (dequeIter != mydeque.end())
		std::cout << "Element found in mydeque: " << *dequeIter << '\n';
	else
		std::cout << "Element not found in mydeque\n";
	return 0;
}