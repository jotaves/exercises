#ifndef _STACKINT_H_
#define _STACKINT_H_

#include <iostream>
using namespace std;

class StackInt{
	public:
		StackInt( int );
		~StackInt( void );
		void push( int );
		int pop( void );
		int top( void ) const;
		inline bool empty( void ) const{ return topo == 0; }
		inline void clear( void ) { topo = 0; }
        inline friend std::ostream &operator<< (std::ostream& _os, const StackInt& _oList )
        {
            _os << "[ ";
            for( int i(0) ; i < _oList.topo ; ++i )
                _os << "{" << _oList.P[ i ] << "} ";
            _os << "]";
            return _os;
        }

	private:
		void resize( void );
		int *P;
		int topo;
		int capacity;
};

#endif