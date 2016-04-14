#ifndef _STACKINT_H_
#define _STACKINT_H_

#include <iostream>

class StackInt{
	public:
		StackInt( int _size = 10 );
		~StackInt( );
		void push( int );
		int pop( void );
		int top( void ) const;
		inline bool empty( void ) const{ return topo == 0; }
		inline void clear( void ) { topo = 0; }

	private:
		int *P;
		int topo;
		int capacity;
};

#endif