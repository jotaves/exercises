// g++ -Wall -std=c++11 src/pgm_ht.cpp -o bin/pgm_ht -I include/
// ./bin/pgm_ht
#include <iostream>
#include <functional>
#include <tuple>
#include <cassert>
#include <string>

#include "hashtbl.hpp"

using namespace std;

#include "account.cpp"

int main( void )
{
    MyHashTable::HashTbl< Account::AcctKey, Account, KeyHash, KeyEqual > accounts(2);
    assert(accounts.isEmpty() == true);
    Account MyAccts[] =
    {
        { "Jose Silva",    1, 1668, 20123, 1500.f },
        { "Carlos Prado",  1, 1668, 35091, 1250.f },
        { "Aline Bastos", 13,   33, 55723,  500.f },
        { "Pedro Gomes",   1, 1801, 87661, 5800.f },
    };

    auto nAccts = sizeof( MyAccts ) / sizeof( Account );

    for ( auto i(0u) ; i < nAccts ; ++i )
    {
        assert (accounts.insert( MyAccts[i].getKey() , MyAccts[i] ) == true);
    }
    
    assert(accounts.isEmpty() == false);

    for ( auto i(0u) ; i < nAccts ; ++i )
    {
        assert (accounts.insert( MyAccts[i].getKey() , MyAccts[i] ) == false);
    }
    
    assert(accounts.isEmpty() == false);

    #ifdef TYPE1

    Account Compare;
    assert ((accounts.insert(12344, { "Pedro Orde",   1, 1801, 87661, 5800.f })) == true);
    assert ((accounts.insert(12344, { "Pedro Ordep",   2, 1801, 87661, 5800.f })) == false);

    accounts.retrieve(35091, Compare);
    assert (Compare.getKey() == MyAccts[1].getKey());
    accounts.showStructure();

    // Checks for accounts and prints records if found
    Account::AcctKey searchKey; // An account key
    Account acct;
    cout << endl;
    accounts.showStructure();
    cout << "Enter account number (CTRL+D to exit program): ";
    while ( cin >> searchKey )
    {
        if ( accounts.retrieve( searchKey, acct ) )
        {
            cout << acct.mNumber << " " << acct.mBalance << endl;
            cout << "Removing this account....\n";
            accounts.remove( acct.getKey() );
        }
        else
            cout << "Account " << searchKey << " not found." << endl;
        
        accounts.showStructure();
        cout << "Enter account number (CTRL+D to exit program): ";
    }
    
    accounts.clear();
    
    #endif

    #ifdef TYPE2
    
    Account Compare;
    assert ((accounts.insert({"Pedro Ordep", 12344}, { "Pedro Orde",   1, 1801, 12344, 5800.f })) == true);
    assert ((accounts.insert({"Pedro Ordep", 12344}, { "Pedro Ordep",   2, 1801, 12344, 5800.f })) == false);

    accounts.retrieve({"Carlos Prado", 35091}, Compare);
    assert (Compare.getKey() == MyAccts[1].getKey());

    // Checks for accounts and prints records if found
    Account::AcctKey searchKey; // An account key
    Account acct;
    cout << endl;
    accounts.showStructure();
    cout << "Enter an account name (CTRL+D to exit program): ";
    while ( getline (cin, searchKey.first) )
    {
        cout << "Enter an account number: ";
        cin >> searchKey.second;
        if ( accounts.retrieve( searchKey, acct ) )
        {
            cout << acct.mClientName << " " << acct.mNumber << " " << acct.mBalance << endl;
            cout << "Removing this account....\n";
            accounts.remove( acct.getKey() );
        }
        else
            cout << "Account " << searchKey.first << " " << searchKey.second << " not found." << endl;
        
        cin.ignore();
        accounts.showStructure();
        cout << "Enter account number (CTRL+D to exit program): ";
    }

    #endif
    
    #ifdef TYPE3
    
    Account::AcctKey searchKey; // An account key
    Account acct;
    Account Compare;
    assert ((accounts.insert( make_tuple("Pedro Ordep",   2, 1801, 12344), { "Pedro Orde",   1, 1801, 12344, 5800.f })) == true);
    assert ((accounts.insert( make_tuple("Pedro Ordep",   2, 1801, 12344), { "Pedro Ordep",   2, 1801, 12344, 5800.f })) == false);

    accounts.retrieve(std::tuple < std::string , int, int, int >("Carlos Prado",  1, 1668, 35091), Compare);
    assert (Compare.getKey() == MyAccts[1].getKey());
    
    accounts.showStructure();
    cout << "Enter an account name (CTRL+D to exit program): ";
    while ( getline (cin, get<0>(searchKey)) )
    {
        cout << "Enter a bank code: ";
        cin >> get<1>(searchKey);
        cout << "Enter a branch code: ";
        cin >> get<2>(searchKey);
        cout << "Enter an account number: ";
        cin >> get<3>(searchKey);        
        if ( accounts.retrieve( searchKey, acct ) )
        {
            cout << acct.mClientName << " "  << acct.mBankCode << " " << acct.mBranchCode << " " <<  acct.mNumber << " " << acct.mBalance << endl;
            cout << "Removing this account....\n";
            accounts.remove( acct.getKey() );
        }
        else
            cout << "Account " << get<0>(searchKey) << " " << get<1>(searchKey) << get<2>(searchKey) << get<3>(searchKey) << " not found." << endl;
        
        cin.ignore();
        accounts.showStructure();
        cout << "Enter account number (CTRL+D to exit program): ";
    }    
    
    #endif

    std::cout << "\n>>> Normal exiting...\n";

    accounts.clear();
    assert(accounts.isEmpty() == true);
    accounts.showStructure();

    return EXIT_SUCCESS;
}
