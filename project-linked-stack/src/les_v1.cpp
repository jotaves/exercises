// This is a stub code (or skeleton code) just to allow the first compilation.

#include <iostream>
#include "les_v1.h"

using namespace std;

//! Prints the list.
/*! This a debugging function that prints the list content.
 *  @param _pAIL Pointer to the head of the list. It NULL, list is empty.
 */
void print( SNPtr _pAIL )
{
    if ( _pAIL == NULL ) cout << "{ }";
    else{
        cout << "{ ";
        while( _pAIL != NULL ){
            cout << _pAIL->miData << " ";
            _pAIL = _pAIL->mpNext;
        }
        cout << "}";
    }
}

//! Length of the list.
/*! Calculates and return the length of the list. Length is zero, if list is empty.
 *  @param _pAIL Pointer to the head of the list. It NULL, list is empty.
 *  @return The length.
 */
int length( SNPtr _pAIL )
{   
    auto i(0u);
    while( _pAIL != NULL ){
        i++;
        _pAIL = _pAIL->mpNext;
    }
    return i;
}


bool empty( SNPtr _pAIL )
{
    return _pAIL == NULL;
}

void clear( SNPtr & _pAIL )
{
    while ( _pAIL != NULL ){
            SNPtr save = _pAIL;
            
            delete [] _pAIL;        
            _pAIL = save->mpNext;
    }
}


bool front( SNPtr _pAIL, int & _retrievedVal )
{
    if (_pAIL != NULL){
        _retrievedVal = _pAIL->miData;
        return true;
    }
    return false;
}


bool back( SNPtr _pAIL, int & _retrievedVal )
{
    if ( _pAIL == NULL ) return false;

    while ( _pAIL != NULL ){
        _retrievedVal = _pAIL->miData;
        _pAIL = _pAIL->mpNext;
    }
    return true;
}


bool pushFront( SNPtr & _pAIL, int _newVal )
{
    SNPtr start;
    try{
        start = new SLLNode;
    }
    catch( const std::bad_alloc & e )
    {
        return false;
    }

    start->miData = _newVal; // Recebe o valor
    start->mpNext = _pAIL; // Aponta para o antigo primeiro ou para NULL.
    _pAIL = start; // Head aponta para o novo primeiro.

    return true;
}


bool pushBack( SNPtr & _pAIL, int _newVal )
{
    if ( _pAIL == NULL ){
        pushFront( _pAIL, _newVal );
    }
    else{
        //SNPtr end;
        SNPtr aux = _pAIL; // Auxiliar para salvar endereço do head.

        // Vai até o último elemento.
        while ( _pAIL->mpNext != NULL ){
            _pAIL = _pAIL->mpNext;
        }

        /*
        O processo abaixo é o mesmo feito no pushFront.
        Poderia ser substituído por pushFront( pAIL->mpNext, _newVal );
        
        try{
            end = new SLLNode;
        }
        catch( const std::bad_alloc &e ){
            return false;
        }
        
        // end recebe o novo valor;
        end->miData = _newVal;
        // end aponta para o final (NULL)
        end->mpNext = _pAIL->mpNext;
        // o antigo elemento final aponta para o novo elemento final;
        _pAIL->mpNext = end;

        */

        if( pushFront( _pAIL->mpNext, _newVal ) )
            _pAIL = aux; // Devolve o endereço do head.
        else
            return false;
    }
    return true;
}


bool popFront( SNPtr & _pAIL, int & _retrievedVal )
{
    if ( _pAIL != NULL ){
        _retrievedVal = _pAIL->miData;
        SNPtr save = _pAIL;
        
        delete [] _pAIL;        
        _pAIL = save->mpNext;

        return true;
    }
    return false;
}


bool popBack( SNPtr & _pAIL, int& _retrievedVal )
{
    if ( _pAIL == NULL ) return false;

    SNPtr save = _pAIL; // Salva endereço do head.
    SNPtr antepenult = NULL; // Salva endereço do antepenúltimo elemento.

    while ( _pAIL->mpNext != NULL ){
        antepenult = _pAIL;
        _pAIL = _pAIL->mpNext;
    }

    _retrievedVal = _pAIL->miData;

    delete [] _pAIL;

    antepenult->mpNext = NULL; // Antepenúltimo se torna o último.
    _pAIL = save; // Head volta à posição de origem.

    return true;
}


SNPtr find( SNPtr _pAIL, int _targetVal )
{
    while ( _pAIL != NULL and _pAIL->mpNext != NULL ){
        if ( _targetVal == _pAIL->mpNext->miData )
            return _pAIL;
        _pAIL = _pAIL->mpNext;
    }
    return NULL;
}


bool insert( SNPtr & _pAIL, SNPtr _pAnte, int _newVal )
{
    if ( _pAnte == NULL ){
        if ( pushFront( _pAIL, _newVal ) ) return true;
        else return false;
    }
    else{
        if ( pushFront( _pAnte->mpNext, _newVal ) ) return true;
        else return false;
    }
}


bool remove( SNPtr & _pAIL, SNPtr _pAnte, int & _retrievedVal )
{
    return true;
}


//**** ===================[ End of les_v1.cpp ]=================== ****// 
