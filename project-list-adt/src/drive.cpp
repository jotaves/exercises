#include "Vector.h"
#include <iostream>

using namespace std;

int main( void ){
	Vector < int > myList;

	cout << "Is empty: " << myList.empty() << "\n";

	cout << "\nList size: " << myList.size() << "\n";

	cout << "\nPushing back 1, 2 and 3.\n";

	myList.push_back(1);
	cout << "\n" << myList.back() << "\n";
	myList.push_back(2);
	cout << "\n" << myList.back() << "\n";
	myList.push_back(3);
	cout << "\n" << myList.back() << "\n";


	cout << "\nIs empty: " << myList.empty() << "\n";

	cout << "\nList size: " << myList.size() << "\n";

	myList.clear();

	myList.push_back(1);
	cout << "\n" << myList.back() << "\n";
	myList.push_back(2);
	cout << "\n" << myList.back() << "\n";
	myList.push_back(3);

	cout << "\n" << myList.back() << "\n";

	cout << "\nList size: " << myList.size() << "\n";

	return 0;
}