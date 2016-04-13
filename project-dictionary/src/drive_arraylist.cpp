/*
--> TO COMPILE WITH DSAL
$ g++ -Wall -std=c++11 src/drive_arraylist.cpp -I include/ -o bin/drive_arraylist
--> TO COMPILE WITH DAL
$ g++ -Wall -std=c++11 src/drive_arraylist.cpp -I include/ -o bin/drive_arraylist -D DAL_ON
--> TO EXECUTE
$ ./bin/drive_arraylist 
*/

/*
 * Test aaplication for the Dictionary with Array Lits or DAL.
 *
 * Try to test as many DAL's methods in varying situations
 * as possible.
 *
 * */
#include <iostream>
#include <sstream>

#include <cmath>
#include <functional>

#include "dal.h"


class MyKeyComparator {
    public:
        int operator ()( int lhs, int rhs ) const {
            if ( lhs < rhs ) return -1;
            else if ( lhs == rhs ) return 0;
            else return 1; // lhs > rhs
        }
};


int main ( ){
    #ifdef DAL_ON
    DAL < int, std::string, MyKeyComparator > myList ( 50 );
    #endif
    #ifndef DAL_ON
    DSAL < int, std::string, MyKeyComparator > myList ( 50 );
    #endif

    cout << ">>> Inserindo {2015003129 , \"Jack\"} " << endl ;
    myList.insert( 2015003129, "Jack" );
    cout << ">>> Inserindo {2014065190 , \"John\"} " << endl ;
    myList.insert ( 2014065190, "John" );

    // Variáveis para utilização nas funções
    std::string returned_s;
    int returned_i;

    cout << "\n>>> Dictionary elements: \n";
    cout << "   " << myList << "\n";

    cout << "\n   Lower key in the dictionary: "<< myList.min() << ".\n";
    cout << "   Highest key in the dictionary: " << myList.max() << ".\n";
    
    if ( myList.sucessor(2014065190, returned_i) )
        cout << "\n   2014065190 successor is " << returned_i << ".\n";
    else cout << "\n   2014065190 successor doesn't exist in the dictionary.\n";

    if ( myList.predecessor(2015003129, returned_i) )
        cout << "   2015003129 ancestor is " << returned_i << ".\n";
    else cout << "   2015003129 ancestor doesn't exist in the dictionary.\n";

    #ifdef DAL_ON
    // WORKS ONLY WITH DAL
    if ( myList.search(2015003129, returned_s ) )
        cout << "\n   2015003129 is " << returned_s << ".\n";
    else cout << "\n  Sorry, 2015003129 wasn't found.\n";

    if ( myList.search(201500, returned_s ) )
        cout << "   2015003129 is " << returned_s << ".\n";
    else cout << "   Sorry, 201500 wasn't found.\n";
    #endif

    if ( myList.remove(2014065190, returned_s) )
        cout << "\n>>> " << returned_s << " was removed.\n";
    else cout << "\n>>> Sorry, 2014065190 wasn't removed.\n";

    if ( myList.remove(2015003129, returned_s) )
        cout << ">>> " << returned_s << " was removed.\n";
    else cout << ">>> Sorry, 2015003129 wasn't removed.\n";

    if( myList.remove(2015029, returned_s) )
        cout << ">>> " << returned_s << "was removed.\n" << endl;
    else cout << ">>> Sorry, 2015029 doesn't exist in the dictionary.\n";

    cout << "\n>>> Dictionary elements: \n";
    cout << "   " << myList << "\n";    
    return 0;
}