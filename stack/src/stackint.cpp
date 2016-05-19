#include "stackint.h"

#include <stdexcept>

StackInt::StackInt( int _size = 10 ) : P(new int[ _size ]), topo(0), capacity( _size )
{ /*empty*/ }

StackInt::~StackInt( void ){
	delete [] P;
}

void StackInt::resize( void ){
	capacity = ( capacity * 2 ) + 1;
	int *Q = new int[ capacity ];
	for( auto i( 0 ); i < topo; i++ ){
		Q[ i ] = P[ i ];
	}
	delete [] P;
	P = Q;
}

void StackInt::push( int _newVal ){
	if ( topo == capacity ) // Não há mais espaço.
		resize();
	P[ topo++ ] = _newVal;
}

int StackInt::pop( void ){
	if ( empty() ) throw std::length_error( "[pop()]: stack size is 0." );
	return P[ --topo ];
}

int StackInt::top( void ) const{
	if ( empty() ) throw std::length_error( "[top()]: stack size is 0." );
	return P[ topo-1 ];
}