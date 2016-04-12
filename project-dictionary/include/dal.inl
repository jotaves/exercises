// g++ -Wall -std=c++11 -I include/ src/drive_arraylist.cpp -o bin/drive_arraylist
// ./bin/drive_arraylist 

/**
 * DAL class implementation.
 *
*/

#include "dal.h"
#include <stdexcept>

// Construtor inicializa TAD.
template < typename Key, typename Data >
DAL<Key,Data>::DAL ( int _iMaxSz ) :
    mi_Length( 0 ),         // Tamanho logico.
    mi_Capacity( _iMaxSz ), // Guardar capacidade atual.
    mpt_Data( nullptr )
{
    if ( _iMaxSz < 0 )          // Nao aceitamos lista com tamanho negativo.
        throw std::invalid_argument( "[DAL()]: Tamanho de lista invalido!" );
    mpt_Data = new NodeAL[ _iMaxSz ]; // Tamanho maximo.
}


template < typename Key, typename Data >
int DAL< Key, Data >::_search( Key _x ) const{ // Metodo de busca auxiliar.
    auto i( 0 );
    for ( /* Empty */ ; mpt_Data[i].id != _x and i < mi_Length ; i++ ){
        /* Empty */
    }
    // Retorna a posição do elemento pesquisado no dicionário. Caso não esteja, retorna o mesmo valor de mi_Length.
    return i;
}

// DAL< Key, Data >::remove is not optimized. It's O(n). Needs to be O(1).
template < typename Key, typename Data >
bool DAL< Key, Data >::remove( const Key & _x, Data & _removed ){	// Remove da lista.
    // idx recebe a posição do elemento no dicionário.
    auto idx = _search( _x );
    
    // Se não está no dicionário (idx == mi_Length), não tem como apagar. Então return false.
    if( idx == mi_Length ) return false;
    
    // Se estiver no dicionário, todos os elementos avançam em direção ao início e retorna o elemento que foi apagado.
    _removed = mpt_Data[ idx ].info;
    
    for ( auto i(idx) ; i < mi_Length-1 ; i++ ){
        mpt_Data[ i ].info = mpt_Data[ i+1 ].info;
        mpt_Data[ i ].id = mpt_Data[ i+1 ].id;
    }
    
    mi_Length--;
    return true;
}

template < typename Key, typename Data >
bool DAL< Key, Data >::search( const Key & _x, Data & _result ) const{	// Busca publica.
	// idx recebe a posição do elemento no dicionário.
    auto idx = _search( _x );

    // Não está no dicionário. Retorna false.
	if( idx == mi_Length ) return false;

    //Está no dicionário. O resultado será passado e retorna true.
	_result = mpt_Data[ idx ].info;
	return true;
}

template< typename Key, typename Data >
bool DAL< Key, Data >::insert( const Key & _novaId, const Data & _novaInfo ){	// Inserir novo elemento.
	// idx recebe a posição do elemento no dicionário.
    auto idx = _search( _novaId );

    // Se não estiver no dicionário, será adicionado.
    if ( idx == mi_Length )
    {
        // Mas se o dicionário já estiver cheio, não será adicionado, retornando false.
        if ( mi_Length == mi_Capacity ){
            throw std::length_error ( "[DAL()]: Tamanho de lista invalido!" );
            return false;
        }

        // Caso contrário, o elemento será adicionado normalmente, retornando true.
        mi_Length++;
        mpt_Data[ idx ].id = _novaId;
        mpt_Data[ idx ].info = _novaInfo;

        return true;
        
    }
    return false;
}

template< typename Key, typename Data >
Key DAL< Key, Data >::max( ) const{
    Key _max = mpt_Data[ 0 ].id;
    for ( auto i(1) ; i < mi_Length ; i++ ){
        if ( mpt_Data[ i ].id > _max ) _max = mpt_Data[ i ].id;
    }
    return _max;
}

template< typename Key, typename Data >
Key DAL< Key, Data >::min( ) const{
        if ( mi_Length > 0 ){
            Key _min = mpt_Data[ 0 ].id;
            for ( auto i(1) ; i < mi_Length ; i++ ){
                if ( mpt_Data[ i ].id < _min ) _min = mpt_Data[ i ].id;
            }
            return _min;
    }
    else throw std::length_error ( "[DAL()]: Tamanho de lista invalido!" );
}


template< typename Key, typename Data >
bool DAL< Key, Data >::sucessor( const Key & _x , Key & _y ) const{
    if ( mi_Length < 2 ) return false;
    _y = max();
    
    for (auto i(0) ; i < mi_Length ; i++){
        if ( mpt_Data[ i ].id < _y &&  mpt_Data[ i ].id > _x ) _y = mpt_Data[ i ].id;
    }
    
    if ( _y == _x ) return false;
    
    return true;
}

template< typename Key, typename Data >
bool DAL< Key, Data >::predecessor( const Key & _x , Key & _y ) const{
    if ( mi_Length < 2 ) return false;
    _y = min();
    
    for ( auto i(0) ; i < mi_Length ; i++ ){
        if ( mpt_Data[ i ].id > _y &&  mpt_Data[ i ].id < _x ) _y = mpt_Data[ i ].id;
    }
    
    if ( _y == _x ) return false;
    
    return true;
}

/**
 * DSAL class implementation.
 *
*/

template < typename Key, typename Data >
Key DSAL< Key, Data >::_search( const Key & _x ) const{ // Metodo de busca auxiliar.
    auto middle = 0, left = 0, right = DAL< Key, Data >::mi_Length - 1;
    // Busca binária.
    while ( left <= right ){
    
        middle = ( left + right ) / 2;
        
        if ( DAL< Key, Data >::mpt_Data[ middle ].id == _x ) return middle;
        else if ( DAL< Key, Data >::mpt_Data[ middle ].id < _x ) left = middle + 1;
        else right = middle - 1;
    }

    // Retorna a posição do elemento pesquisado no dicionário. Caso não esteja, retorna o mesmo valor de mi_Length.
    return DAL< Key, Data >::mi_Length;
}

template < typename Key, typename Data >
bool DSAL< Key, Data >::insert(const Key &_novaId, const Data &_novaInfo){
    // idx recebe a posição do elemento no dicionário.
    auto idx = _search( _novaId );

    // Se não estiver no dicionário, será adicionado.
    if ( idx == DAL<Key, Data>::mi_Length )
    {
        // Mas se o dicionário já estiver cheio, não será adicionado, retornando false.
        if ( DAL< Key, Data >::mi_Length == DAL< Key, Data >::mi_Capacity ){
            throw std::length_error ( "[DSAL()]: Tamanho de lista invalido!" );
            return false;
        }

        // Caso contrário, o elemento será adicionado normalmente, retornando true.
        DAL< Key, Data >::mi_Length++;
        auto i( DAL< Key, Data >::mi_Length-1 );

        // Como é ordenado, deve-se colocar o elemento na posição correta. Logo, alguns elementos são afastados.
        while ( i > 0 and _novaId < DAL< Key, Data >::mpt_Data[i-1].id ){
            DAL< Key, Data >::mpt_Data[ i ].id = DAL< Key, Data >::mpt_Data[ i-1 ].id;
            DAL< Key, Data >::mpt_Data[ i ].info = DAL< Key, Data >::mpt_Data[ i-1 ].info;
            i--;
        }
        
        DAL< Key, Data >::mpt_Data[ i ].id = _novaId;
        DAL< Key, Data >::mpt_Data[ i ].info = _novaInfo;

        return true;
    }
    return false;
}

template < typename Key, typename Data >
bool DSAL< Key, Data >::remove( const Key &_x, Data & _removed ){
    // idx recebe a posição do elemento no dicionário.
    auto idx = _search( _x );
    
    // Se não está no dicionário (idx == mi_Length), não tem como apagar. Então return false.
    if( idx == DAL< Key, Data >::mi_Length ) return false;
    
    // Se estiver no dicionário, todos os elementos avançam em direção ao início e retorna o elemento que foi apagado.
    _removed = DAL< Key, Data >::mpt_Data[ idx ].info;
    
    for ( auto i( idx ) ; i < DAL< Key, Data >::mi_Length-1 ; i++ ){
        DAL< Key, Data >::mpt_Data[ i ].info = DAL< Key, Data >::mpt_Data[ i+1 ].info;
        DAL< Key, Data >::mpt_Data[ i ].id = DAL< Key, Data >::mpt_Data[ i+1 ].id;
    }
    
    DAL<Key, Data>::mi_Length--;
    return true;    
}

template < typename Key, typename Data >
Key DSAL< Key, Data >::min( ) const{  // Recupera a menor chave do dicionário.
    if ( DAL< Key, Data >::mi_Length > 0 ){
        return DAL< Key, Data >::mpt_Data[ 0 ].id;
    }
    else throw std::length_error ( "[DSAL()]: Tamanho de lista invalido!" );
}

template < typename Key, typename Data >
Key DSAL< Key, Data >::max( ) const{ // Recupera a maior chave do dicionário.
    if ( DAL< Key, Data >::mi_Length > 0 ){
        return DAL< Key, Data >::mpt_Data[ DAL< Key, Data >::mi_Length-1 ].id;
    }
    else throw std::length_error ( "[DSAL()]: Tamanho de lista invalido!" );
}


// Recupera em _y a chave sucessora a _x, se existir(true).
template < typename Key, typename Data >
bool DSAL< Key, Data >::sucessor( const Key &_x, Key &_y ) const{
    // Se o tamanho do dicionário não for suficiente para ter um sucessor.    
    if ( DAL< Key, Data >::mi_Length < 2 ) return false;
    auto idx = _search( _x );

    // Se a posição do elemento _x for a última (sem sucessor) ou não estiver no dicionário.
    if ( idx >= DAL< Key, Data >::mi_Length-1 ) return false;

    /*
    if ( idx == DAL< Key, Data >::mi_Length){
        _y = max();
        
        for (auto i(0) ; i < DAL< Key, Data >::mi_Length ; i++){
            if (DAL< Key, Data >::mpt_Data[ i ].id < _y &&  DAL< Key, Data >::mpt_Data[ i ].id > _x ) _y = DAL< Key, Data >::mpt_Data[ i ].id;
        }
        return true;
    }
    */

    _y = DAL< Key, Data >::mpt_Data[ idx+1 ].id;
    return true;
}

// Recupera em _y a chave antecessora a _x, se existir(true).
template < typename Key, typename Data >
bool DSAL< Key, Data >::predecessor( const Key &_x, Key &_y ) const{
    // Se o tamanho do dicionário não for suficiente para ter um predecessor.
    if ( DAL< Key, Data >::mi_Length < 2 ) return false;
    auto idx = _search( _x );
    
    // Se a posição do elemento _x for a primeira (sem sucessor) ou não estier no dicionário.
    if ( idx < 1 or idx == DAL< Key, Data >::mi_Length ) return false;
    
    /*
    if ( idx == DAL< Key, Data >::mi_Length ){
        _y = min();
        
        for (auto i(0) ; i < DAL< Key, Data >::mi_Length ; i++){
            if (DAL< Key, Data >::mpt_Data[ i ].id > _y &&  DAL< Key, Data >::mpt_Data[ i ].id < _x ) _y = DAL< Key, Data >::mpt_Data[ i ].id;
        }     
        return true;   
    }
    */

    _y = DAL< Key, Data >::mpt_Data[ idx-1 ].id;

    return true;
}