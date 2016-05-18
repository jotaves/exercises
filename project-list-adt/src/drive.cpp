// g++ -Wall -std=c++11 src/drive.cpp -o bin/drive -I include/
// ./bin/drive
#include <iostream>
#include <assert.h>

#include "vector.h"

using namespace std;

int main( void ){
	Vector < int > myVector;

	assert(myVector.empty() == true);
	assert(myVector.size() == 0);

	// Pushing 3 elements (1, 2, 3)
	myVector.push_back(1);
	assert(myVector.back() == 1);
	myVector.push_back(2);
	assert(myVector.back() == 2);
	myVector.push_back(3);
	assert(myVector.back() == 3);


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

	// Clearing vector
	myVector.clear();
	assert(myVector.size() == 0);
	// Pop back with no elements
	myVector.pop_back();

	// Pushing back new element
	myVector.push_back(1);
	assert(myVector.back() == 1);	
	myVector.push_back(2);	
	assert(myVector.back() == 2);
	myVector.pop_back();
	assert(myVector.back() == 1 and myVector.size() == 1);

	return 0;
}