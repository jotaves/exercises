// g++ -Wall -std=c++11 src/pgm_ht.cpp -o bin/pgm_ht -I include/
// ./bin/pgm_ht
#include <iostream>
#include <functional>
#include <tuple>
#include <cassert>
#include <string>

#include "hashtbl.h"

using namespace std;

struct Account
{
    std::string mClientName;// (key) Client's name.
    int mBankCode;          // (key) Bank code.
    int mBranchCode;        // (key) Branch code.
    int mNumber;            // (key) Account number.
    float mBalance;         // Account balance.
    
    #ifdef TYPE1
    using AcctKey = int;
    #endif
    #ifdef TYPE2
    using AcctKey = std::pair < std::string, int >;
    #endif

    Account( std::string _Name = "<empty>",
             int _BankCode = 1,  // Banco do Brasil.
             int _BranchCode = 1668, // Agencia UFRN.
             int _Number = 0,
             float _Balance = 0.f )
        :  mClientName( _Name ),
           mBankCode( _BankCode ),
           mBranchCode( _BranchCode ), 
           mNumber( _Number ), 
           mBalance( _Balance )
        { /* Empty */ }

    #ifdef TYPE1
    /*!
     * \brief Gera a chave (versão 1) que eh igual a conta corrente.
     */
    AcctKey getKey () const
    {
        return mNumber;
    }
    #endif

    #ifdef TYPE2
    AcctKey getKey () const
    {
        return {mClientName, mNumber};
    }

    #endif

    const Account& operator= ( const Account& rhs )
    {
        // Avoid assigning to itself.
        if( this != &rhs )
        {
            // Copy new values.
            this->mClientName = rhs.mClientName;
            this->mBankCode   = rhs.mBankCode;
            this->mBranchCode = rhs.mBranchCode;
            this->mNumber     = rhs.mNumber;
            this->mBalance    = rhs.mBalance;
        }
        return *this;
    }

    //TODO friend para imprimir
    inline friend std::ostream &operator<< ( std::ostream& _os, const Account& _acc )
    {
        _os << "[ Client: <"  << _acc.mClientName <<
               "> Bank: <"    << _acc.mBankCode <<
               "> Branch: <"  << _acc.mBranchCode <<
               "> Number: <"  << _acc.mNumber <<
               "> Balance: <" << _acc.mBalance << "> ]";
        return _os;
    }
};

#ifdef TYPE1
struct KeyHash {
    std::size_t operator()(const Account::AcctKey& k) const
    {
        return  std::hash<int>()( k );
    }
};

struct KeyEqual {
    bool operator()(const Account::AcctKey& lhs, const Account::AcctKey& rhs) const
    {
        return lhs == rhs;
    }
};

#endif

#ifdef TYPE2

struct KeyHash {
    std::size_t operator()(const Account::AcctKey& k) const
    {
        return (std::hash<std::string>()( k.first ) xor std::hash<int>()( k.second));
    }
};

struct KeyEqual {
    bool operator()(const Account::AcctKey& lhs, const Account::AcctKey& rhs) const
    {
        return lhs.first == rhs.first and lhs.second == rhs.second;
    }
};

#endif


int main( void )
{
    MyHashTable::HashTbl< Account::AcctKey, Account, KeyHash, KeyEqual > accounts(2); // Hash table shall heve size 23.
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

    for ( auto i(0u) ; i < nAccts ; ++i )
    {
        assert (accounts.insert( MyAccts[i].getKey() , MyAccts[i] ) == false);
    }

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

        cout << "Enter account number (CTRL+D to exit program): ";
    }
    
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
    cout << "Enter an account name (CTRL+D to exit program): ";
    while ( getline (cin, searchKey.first) )
    {
        cout << "Enter an account number: ";
        cin >> searchKey.second;
        accounts.showStructure();
        if ( accounts.retrieve( searchKey, acct ) )
        {
            cout << acct.mClientName << " " << acct.mNumber << " " << acct.mBalance << endl;
            cout << "Removing this account....\n";
            accounts.remove( acct.getKey() );
        }
        else
            cout << "Account " << searchKey.first << " " << searchKey.second << " not found." << endl;
        cin.ignore();
        cout << "Enter account number (CTRL+D to exit program): ";
    }

    #endif

    std::cout << "\n>>> Normal exiting...\n";

    //accounts.clear();

    return EXIT_SUCCESS;
}
