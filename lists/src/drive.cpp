/*!
 *  @mainpage TAD List
 *  @authors João Victor Bezerra Barboza, Carlos Vincius Fernanes Rodrigues
 *  @date Maio, 2016
 *  @copyright Copyright &copy; 2016. Todos os direitos reservados.
 *  @version 1.0
 *
 *  @file drive.cpp
 *  @brief Driver File
 *
 *  Arquivo que dá inicio à todo o código, ramificando para myFList, foward myFList ou vector.
 */

#include <iostream>
#include <cassert>

#include "vector.h"
#include "forward_list.h"

using namespace std;

int main( void ){
	/* Testing Vector class */
	Vector < int > myVector;

	// Testing capacity(), empty() and size()
	assert(myVector.capacity() == 0);
	assert(myVector.empty() == true);
	assert(myVector.size() == 0);

	// Pushing 3 elements (1, 2, 3)
	myVector.push_back(1);
	assert(myVector.back() == 1);
	myVector.push_back(2);
	assert(myVector.back() == 2);
	myVector.push_back(3);
	assert(myVector.back() == 3);
	
	// Testing capacity()
	assert(myVector.capacity() == 4);
	
	// Testing []
	assert(myVector[0] == 1);
	assert(myVector[2] == 3);
	
	// Testing at
	assert(myVector.at(0) == 1);
	assert(myVector.at(2) == 3);
	
	// Testing iterators
	Vector<int>::iterator it (myVector.begin());
	Vector<int>::iterator its (myVector.end());
	assert(*it == 1);
	it++;
	assert(*it == 2);
	++it;
	assert(*it == 3);
	it--;
	assert(*it == 2);
	--it;
	assert(*it == 1);
	assert((it == its) == false);
	assert((it != its) == true);
	it = myVector.end();
	assert((it == its) == true);
	assert((it != its) == false);
	
	// Testing empty() and size()
	assert(myVector.empty() == false);
	assert(myVector.size() == 3);

	// Clearing vector
	myVector.clear();
	assert(myVector.empty() == true);

	// Pushing 4 elements (4, 3, 2, 1)
	myVector.push_back(4);
	assert(myVector.back() == 4);
	myVector.push_back(3);
	assert(myVector.back() == 3);
	myVector.push_back(2);
	assert(myVector.back() == 2);
	myVector.push_back(1);
	assert(myVector.back() == 1);
	
	// Testing size()
	assert(myVector.size() == 4);

	// Popping back elements
	myVector.pop_back();
	assert(myVector.back() == 2);
	assert(myVector.size() == 3);
	myVector.pop_back();
	assert(myVector.back() == 3);
	assert(myVector.size() == 2);
	myVector.push_back(1);
	assert(myVector.back() == 1);
	
	// Clearing vector, testing size() and capacity()
	myVector.clear();
	assert(myVector.size() == 0);
	assert(myVector.capacity() == 4);
	// Testing pop back with no elements
	myVector.pop_back();

	// Pushing back new element
	myVector.push_back(1);
	assert(myVector[0] == 1);
	assert(myVector.back() == 1);	
	myVector.push_back(2);	
	assert(myVector.back() == 2);
	myVector.pop_back();
	assert(myVector.back() == 1 and myVector.size() == 1);


	// Assign and testing some functions
	myVector.assign(1);
	assert(myVector[0] == 1);
	assert(myVector.at(0) == 1);
	assert(myVector[myVector.capacity()-1] == 1);
	assert(myVector.at(myVector.capacity()-1) == 1);
	assert(myVector.capacity() == 4);
	

	// Forward_myFList
	Forward_list<int> myFList;
	
	// Testing size() and empty()
	assert(myFList.size() == 0);
	assert(myFList.empty() == true);
	
	// Testing push_front() and push_back()
	myFList.push_front(2);
	assert (myFList.back() == 2);
	assert(myFList.front() == 2);
	assert(myFList.empty() == false);
	myFList.push_front(1);
	assert (myFList.back() == 2);
	assert(myFList.front() == 1);
	myFList.push_back(3);
	assert (myFList.back() == 3);
	assert(myFList.front() == 1);
	myFList.push_back(4);
	assert (myFList.back() == 4);
	assert(myFList.front() == 1);
	
	// Testing pop_front() and pop_back()
	assert (myFList.pop_front() == 1);
	assert (myFList.pop_back() == 4);
	assert (myFList.pop_front() == 2);
	assert (myFList.pop_back() == 3);
	assert (myFList.size() == 0);
	assert(myFList.empty() == true);
	
	myFList.clear();
	
	// Doing everything again
	myFList.push_front(2);
	assert (myFList.back() == 2);
	assert(myFList.front() == 2);
	assert(myFList.empty() == false);
	myFList.push_front(1);
	assert (myFList.back() == 2);
	assert(myFList.front() == 1);
	myFList.push_back(3);
	assert (myFList.back() == 3);
	assert(myFList.front() == 1);
	myFList.push_back(4);
	assert (myFList.back() == 4);
	assert(myFList.front() == 1);

	// Testing assign
	myFList.assign(10);
	assert (myFList.size() == 4);
	assert (myFList.pop_back() == 10);
	assert (myFList.pop_back() == 10);
	assert (myFList.pop_back() == 10);
	assert (myFList.pop_back() == 10);


	myFList.clear();
	myFList.push_back(1);
	myFList.push_back(2);
	myFList.push_back(3);
	myFList.push_back(4);

	// Testing iterators
	Forward_list<int>::iterator it1 (myFList.begin());
	Forward_list<int>::iterator its1 (myFList.end());
	assert(*it1 == 1);
	it1++;
	assert(*it1 == 2);
	++it1;
	assert(*it1 == 3);
	it1++;
	assert(*it1 == 4);
	assert((it1 == its1) == true);
	assert((it1 != its1) == false);
	it1 = myFList.begin();
	assert((it1 == its1) == false);
	assert((it1 != its1) == true);
	
	std::cout << ">>> Leaving successfully.\n";
	return EXIT_SUCCESS;
}
