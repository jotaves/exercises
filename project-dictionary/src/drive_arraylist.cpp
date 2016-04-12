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




int main ( )
{
    DAL< int, std::string  >  myList( 50 ); // Lista de no máximo 50 elementos.
    std::string retur;
    auto x(0);
    std::cout << "\n>>> myList: " << myList << std::endl;
    
    myList.insert( 15, "dado 1" );
    myList.insert( 2, "dado 2" );
    myList.insert( 8, "dado 3" );
    
    cout << endl << myList.max() << endl;
    cout << endl << myList.min() << endl;
    cout << endl << myList.predecessor(8, x) << endl;
    cout << endl << x << endl;
    cout << endl << myList.sucessor(8, x) << endl;
    cout << endl << x << endl;
    
    std::cout << "\n>>> myList: " << myList << std::endl;
    
    myList.remove( 15, retur );
    myList.remove( 2, retur );
    myList.remove( 8, retur );
    myList.remove( 9, retur );
    
    std::cout << "\n>>> myList: " << myList << std::endl;    
    //std::cout << retur;    

    std::cout << "\n>>> Normal ending...\n\n";

    return EXIT_SUCCESS;
}

