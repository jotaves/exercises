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
 *  Arquivo que dá inicio à todo o código, ramificando para list, foward list ou vector.
 */


// g++ -Wall -std=c++11 src/drive.cpp -o bin/drive -I include/
// ./bin/drive
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
	
	
	// Forward_List
	Forward_List<int> list;
	
	assert(list.size() == 0);
	assert(list.empty() == true);
	
	list.push_front(2);
	assert (list.back() == 2);
	list.push_front(1);
	assert (list.back() == 2);
	list.push_back(3);
	assert (list.back() == 3);
	list.push_back(4);
	assert (list.back() == 4);
	
	assert (list.pop_front() == 1);
	assert (list.pop_back() == 4);
	assert (list.pop_front() == 2);
	assert (list.pop_back() == 3);
	assert (list.size() == 0);
	return 0;
}