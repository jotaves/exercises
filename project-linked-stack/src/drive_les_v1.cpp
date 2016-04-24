// Para compilar: g++ -Wall -std=c++11 src/drive_les_v1.cpp src/les_v1.cpp -o bin/drive_les_v1 -I include/


#include "les_v1.h"
#include <iostream>
#include <cassert>
using std::cout;


int main ( void ) {
    SNPtr pHead = NULL;// nullptr;
    SNPtr example = new SLLNode;

    int retrn;
    print(pHead);
    cout << " Is empty: " << empty(pHead) << "\n\n";
    
    cout << "Adding from 1 to 3 at front." << "\n";
    pushFront( pHead, 1 );   
    print(pHead);
    cout << "\n";

    pushFront( pHead, 2 );
    print(pHead);
    cout << "\n";    
    
    pushFront( pHead, 3 );
    print(pHead);
    cout << "\n\n";

	cout << "Adding 0 and -1 at back." << "\n";
    pushBack( pHead, 0 );
    print(pHead);
    cout << "\n";

    pushBack( pHead, -1 );
    print(pHead);
    cout << "\nLength: " << length(pHead) << "\n\n";

    popFront( pHead, retrn );
    cout << "Pop front: " << retrn << std::endl;
    print(pHead);
    cout << "\n\n";

	popBack( pHead, retrn );
    cout << "Pop back: " << retrn << "\n";
    print(pHead);
    cout << "\n\n";

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
   	cout << "Clear: \n";
    clear(pHead);

    print(pHead);
    cout << "\n";

    cout << "Length: " << length(pHead) << "\n";

    if ( front(pHead, retrn) ){
    	cout << "Front: " << retrn << std::endl;
    } 
    if ( back(pHead, retrn) ){
    	cout << "Back: " << retrn << std::endl;
    }

    cout << "Is empty: " << empty(pHead) << std::endl;

    cout << "\nInsert( pHead, NULL, 3 ): \n";
    insert( pHead, NULL, 3 );
    print(pHead);
    cout << "\n";

	cout << "\nInsert( pHead, find( pHead, 3 ), 5 ): \n";
    insert( pHead, find( pHead, 3 ), 5 );
    print(pHead);
    cout << "\n";

    cout << "\nInsert( pHead, find( pHead, 3 ), 4 ): \n";
    insert( pHead, find( pHead, 3 ), 4 );
    print(pHead);
    cout << "\n";


    cout << "\nRemove( pHead, find( pHead, 3 ), retrn ):\n";
    if ( remove( pHead, find( pHead, 3 ), retrn ) ) cout << retrn << " deleted\n";
    print(pHead);
    cout << "\n";    

    cout << "\nRemove( pHead, NULL, retrn ): \n";
    if ( remove( pHead, NULL, retrn ) ) cout << retrn << " deleted\n";
    print(pHead);
    cout << "\n";

    cout << "\nRemove( pHead, find( pHead, 4 ), retrn ): \n";
    if ( remove( pHead, find( pHead, 4 ), retrn ) ) cout << retrn << " deleted\n"; 
    print(pHead);
    cout << "\n";

    cout << "\nRemove( pHead, find( pHead, 4 ), retrn ): \n";
    if (remove( pHead, find( pHead, 4 ), retrn ) ) cout << "\n" << retrn << " deleted\n";
    else cout << "Nothing deleted\n";
    print(pHead);
    cout << "\n";

    cout << "\n>>> Normal exiting...\n";
    return EXIT_SUCCESS;
}
