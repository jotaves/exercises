#include <cmath>
#include <list>

int isPrime(int _size){
    if (_size < 2) return false;
    if (_size == 2) return true;

    for(auto i(2); i <= ceil(sqrt(_size)); i++){
        /*std::cout << _size << "\n";
        std::cout << _size % i << "\n";*/
        if (_size % i == 0) return false;
    }
    return true;
}

// g++ -Wall -std=c++11 hash_table/src/pgm_ht.cpp -I hash_table/include/ -o hash_table/bin/pgm_ht 
// g++ -Wall -std=c++11 src/pgm_ht.cpp -I include/ -o bin/pgm_ht 
// ./bin/pgm_ht
// ./hash_table/bin/pgm_ht

#include <iostream>

#include "hashtbl.h"

//! MyHashTable namespace encapsulates all class related to a simple hash function definition.
namespace MyHashTable {

    //----------------------------------------------------------------------------------------
    //! Default construtor.
    /*! Creates a hash table of the required capacity, which uses an external hash function
     *  that maps keys to unsigned long integers.
     *  If no external hash function is provided, an \r UndefinedHashFunctionException is generated.
     *  \param _initSize Required hash table capacity.
     *  \param _pfHF Pointer to an external hash function that does the first hashing and returns an unsigned long int.
     *  \throw UndefinedHashFunctionException if no external hash function is provided.
    */
    template < typename KeyType, typename DataType, typename KeyHash, typename KeyEqual >
    HashTbl< KeyType, DataType, KeyHash, KeyEqual >::HashTbl ( int _initSize ) : mCount( 0u ){
        while(!isPrime(_initSize)){
            _initSize++;
        }
        mSize = _initSize;
        mpDataTable = new std::list< Entry >[mSize];
        //std::cout << mSize << "\n";
        //std::cout << mCount << "\n";
    }

    //----------------------------------------------------------------------------------------
    //! Destrutor that just frees the table memory, clearing all collision lists.
    template < typename KeyType, typename DataType, typename KeyHash, typename KeyEqual >
    HashTbl< KeyType, DataType, KeyHash, KeyEqual >::~HashTbl ()
    {
        // limpar bloco por bloco
        clear();
        delete [] mpDataTable;
    }

    //----------------------------------------------------------------------------------------
    //! Inserts data into the hash table.
    /*! For an insertion to occur, the client code should provide a key and the data itself
     *  If the data is already stored in the table, the function updates the data with the
     *  new information provided.
     *  \param _newKey Key associated with the data, used to get to the stored information.
     *  \param _newDataItem Data to be stored or updated, in case the information is already stored in the hash table.
     *  \return true if the data is already stored in the table and it is updated; false, otherwise.
     *  \throw std::bad_alloc In case no memory is available for dynamic allocation required in the insertion procedure.
    */
    template < typename KeyType, typename DataType, typename KeyHash, typename KeyEqual >
    bool HashTbl< KeyType, DataType, KeyHash, KeyEqual >::insert ( const KeyType & _newKey, const DataType & _newDataItem ) throw ( std::bad_alloc )
    {
        if (mCount/mSize > 1) rehash();
        KeyHash hash;
        KeyEqual compare;
        // Faz o mod e acha o lugar que deve estar na lista
        auto place (hash(_newKey) % mSize);
        // Percorre a lista dentro da mpDataTable[place] e procura se há algum elemento com chave igual
        for(auto i(mpDataTable[place].begin()); i != mpDataTable[place].end(); i++){
            if (compare((*i).mKey, _newKey)){
                // Se a chave for igual, sobrescreve dados do elemento
                (*i).mData = _newDataItem;
                return false;
            }
        }
        // Se não houver chave igual, adiciona elemento à lista
        mpDataTable[place].emplace_back(_newKey, _newDataItem);
        mCount++;
        return true;
    }


    //----------------------------------------------------------------------------------------
    //! Removes data from the hash table.
    /*! Removse a data item from the table, based on the key associated with the data.
     *  If the data cannot be found, false is returned; otherwise, true is returned instead.
     *  \param _searchKey Data key to search for in the table.
     *  \return true if the data item is found; false, otherwise.
    */
    template < typename KeyType, typename DataType, typename KeyHash, typename KeyEqual >
    bool HashTbl< KeyType, DataType, KeyHash, KeyEqual >::remove ( const KeyType & _searchKey )
    {
        KeyHash hash;
        KeyEqual compare;

        auto place (hash(_searchKey) % mSize);

        for(auto i(mpDataTable[place].begin()); i != mpDataTable[place].end(); i++){
            if (compare((*i).mKey, _searchKey)){
                // Se a chave for igual, sobrescreve dados do elemento
                mpDataTable[place].erase(i);
                mCount--;
                return true;
            }
        }
        return false;
    }

    //----------------------------------------------------------------------------------------
    //! Retrieves data from the table.
    /*! Retrieves a data item from the table, based on the key associated with the data.
     *  If the data cannot be found, false is returned; otherwise, true is returned instead.
     *  \param _searchKey Data key to search for in the table.
     *  \param _dataItem Data record to be filled in when data item is found.
     *  \return true if the data item is found; false, otherwise.
    */
    template < typename KeyType, typename DataType, typename KeyHash, typename KeyEqual >
    bool HashTbl< KeyType, DataType, KeyHash, KeyEqual >::retrieve ( const KeyType & _searchKey, DataType & _dataItem ) const
    {
        KeyHash hash;
        KeyEqual compare;
        auto place(hash(_searchKey) % mSize);
        for(auto i(mpDataTable[place].begin()); i != mpDataTable[place].end(); i++){
            if (compare((*i).mKey, _searchKey)){
                _dataItem = (*i).mData;
                return true;
            }
        }
        return false;
    }

    //! Clears the data table.
    template < typename KeyType, typename DataType, typename KeyHash, typename KeyEqual >
    void HashTbl< KeyType, DataType, KeyHash, KeyEqual >::clear ()
    {
        for(auto i(0); i < mSize; i++){
            mpDataTable[i].erase (mpDataTable[i].begin(), mpDataTable[i].end());
        }
        mCount = 0;
        /*
        delete [] mpDataTable;
        mpDataTable = new std::list< Entry >[mSize];
        */
    }

    //! Tests whether the table is empty.
    /*!
     * \return true is table is empty, false otherwise.
     */
    template < typename KeyType, typename DataType, typename KeyHash, typename KeyEqual >
    bool HashTbl< KeyType, DataType, KeyHash, KeyEqual >::isEmpty () const
    {
        return ( mCount == 0 );
    }

    //! Counts the number of elements currently stored in the table.
    /*!
     * \return The current number of elements in the table.
     */
    template < typename KeyType, typename DataType, typename KeyHash, typename KeyEqual >
    unsigned long int HashTbl< KeyType, DataType, KeyHash, KeyEqual >::count () const
    {
        return mCount;
    }

    //! Prints out the hash table content.
    template < typename KeyType, typename DataType, typename KeyHash, typename KeyEqual >
    void HashTbl< KeyType, DataType, KeyHash, KeyEqual >::showStructure () const
    {
        KeyHash hashFn;

        // Traverse the list associated with the based address (idx), calculated before.
        for( auto i(0) ; i < mSize; ++i )
        {
            std::cout << i << " :{ key=";
            for( auto & e : mpDataTable[ i ] )
            {
                std::cout << hashFn( e.mKey ) << " ; " << e.mData << " " ;
            }
            std::cout << "}\n";
        }
    }
    

    template < typename KeyType, typename DataType, typename KeyHash, typename KeyEqual >
    void HashTbl< KeyType, DataType, KeyHash, KeyEqual >::rehash( void ){
        KeyHash hash;

        auto newSize (mSize*2);
        std::cout << "old size: " << mSize << "\n";
        while(!isPrime(newSize)){
            newSize++;
        }
        
        std::list< Entry > *aux = new std::list< Entry >[newSize];      
        for(auto place(0u); place < mSize; place++){
            for(auto i(mpDataTable[place].begin()); i != mpDataTable[place].end(); i++){
                auto newPlace (hash((*i).mKey) % newSize);
                aux[newPlace].push_back(*i); 
            }
        }
        
        delete [] mpDataTable;
        mSize = newSize;
        std::cout << "new size: " << mSize << "\n";
        mpDataTable = aux;
    }

} // namespace MyHashTable
