// Para compilar: g++ -Wall -std=c++11 src/drive_les_v1.cpp src/les_v1.cpp -o bin/drive_les_v1 -I include/


#include "les_v1.h"
#include <iostream>
#include <cassert>
using std::cout;


int main ( void ) {
    SNPtr pHead = NULL;// nullptr;
    SNPtr example = new SLLNode;

    int _front, _back;

    cout << "Is empty:" << empty(pHead) << "\n\n";
    
    cout << "Adding from 1 to 3 at front." << std::endl;
    print(pHead);
    cout << "\n";

    pushFront( pHead, 1 );   
    print(pHead);
    cout << "\n";

    pushFront( pHead, 2 );
    print(pHead);
    cout << "\n";    
    
    pushFront( pHead, 3 );
    print(pHead);
    cout << "\n\n";

	cout << "Adding 0 at back." << "\n";
    pushBack( pHead, 0 );
    print(pHead);
    cout << "\n\n";

    popFront( pHead, _front );
    cout << "Pop front: " << _front << std::endl;
    print(pHead);
    cout << "\n\n";

	popBack( pHead, _back );
    cout << "Pop back: " << _back << "\n";
    print(pHead);
    cout << "\n\n";
    
    clear(pHead);
    
    cout << "Searching from 0 to 3: \n";
    int toFind = 0;
	while ( toFind < 4 ){
	   	example = find( pHead, toFind );
	    
	    if (example != NULL){
	    	cout << example->miData << " is " << toFind << " predecessor.\n";
	    }
	    else cout << toFind << " not found/is the first element or stack is empty." << "\n";
		++toFind;
	}
	cout << "\n";

    print(pHead);
    cout << "\n";

    cout << "Length: " << length(pHead) << "\n";

    front(pHead, _front);
    back(pHead, _back);

    cout << "Front: " << _front << std::endl << "Back: " << _back << std::endl;

    cout << "Is empty: " << empty(pHead) << std::endl;

    cout << "\nInsert( pHead, find( pHead, 1 ), 3 ): \n";
    insert( pHead, find( pHead, 1 ), 3 );
    print(pHead);

	cout << "\n\nInsert( pHead, NULL, 4 ): \n";
    insert( pHead, NULL, 4 );
    print(pHead);

    cout << "\nInsert( pHead, find( pHead, 1 ), 9 ): \n";
    insert( pHead, find( pHead, 1 ), 9 );
    print(pHead);    

    cout << "\n\n>>> Normal exiting...\n";
    return EXIT_SUCCESS;
}
