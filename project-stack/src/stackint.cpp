#include "stackint.h"

StackInt::StackInt( int _size ) :
	topo( 0 ),
	capacity( _size ),
	P( new int[ _size ] )
{ /* Empty */ }

StackInt::~StackInt(){
	delete [] P;
}

void StackInt::push( int _newVal ){
	if ( topo == capacity ) // Não há mais espaço.
		resize ( 2*capacity );
	P[topo++] = _newVal;
}