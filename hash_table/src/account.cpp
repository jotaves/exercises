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
    #ifdef TYPE3
    using AcctKey = std::tuple < std::string , int, int, int >;
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
    
    #ifdef TYPE3
    AcctKey getKey () const
    {
        return std::tuple < std::string , int, int, int >(mClientName, mBankCode, mBranchCode, mNumber);
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

#ifdef TYPE3

struct KeyHash {
    std::size_t operator()(const Account::AcctKey& k) const
    {
        return (std::hash<std::string>()(get<0>(k)) xor std::hash<int>()(get<1>(k)) xor std::hash<int>()(get<2>(k)) xor std::hash<int>()(get<3>(k)));
    }
};

struct KeyEqual {
    bool operator()(const Account::AcctKey& lhs, const Account::AcctKey& rhs) const
    {
        return get<0>(lhs) == get<0>(rhs) and get<1>(lhs) == get<1>(rhs)  and get<2>(lhs) == get<2>(rhs) and get<3>(lhs) == get<3>(rhs);
    }
};

#endif