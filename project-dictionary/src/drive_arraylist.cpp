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
    DSAL< int, std::string > myList2( 50 );

    std::string retur;
    //auto x(0);
    std::cout << "\n>>> myList: " << myList << std::endl;
    std::cout << "\n>>> myList2: " << myList2 << std::endl;
    
    myList.insert( 15, "dado 1" );
    myList.insert( 2, "dado 2" );
    myList.insert( 8, "dado 3" );

    myList2.insert( 2, "dado 1");
    myList2.insert( 3, "dado 2");
    myList2.insert( 1, "dado 3");
    
    /*
    cout << endl << myList.max() << endl;
    cout << endl << myList.min() << endl;
    cout << endl << myList.predecessor(8, x) << endl;
    cout << endl << x << endl;
    cout << endl << myList.sucessor(8, x) << endl;
    cout << endl << x << endl;
    */


    cout << endl << myList.max() << endl;
    cout << endl << myList2.max() << endl;

    auto pre = 0, suc = 0;

    myList2.predecessor( 2, pre );
    myList2.sucessor( 2, suc );

    cout << endl << pre << endl << suc << endl;

    std::cout << "\n>>> myList: " << myList << std::endl;
    std::cout << "\n>>> myList2: " << myList2 << std::endl;
    
    myList.remove( 15, retur );
    myList.remove( 2, retur );
    myList.remove( 8, retur );
    myList.remove( 9, retur );

    myList2.remove( 2, retur);
       std::cout << "\n>>> myList2: " << myList2 << std::endl; 
    myList2.remove( 3, retur);
       std::cout << "\n>>> myList2: " << myList2 << std::endl; 
    myList2.remove( 1, retur);
    
    std::cout << "\n>>> myList: " << myList << std::endl;   
    std::cout << "\n>>> myList2: " << myList2 << std::endl; 
    //std::cout << retur;


    std::cout << "\n>>> Normal ending...\n\n";

    return EXIT_SUCCESS;
}

