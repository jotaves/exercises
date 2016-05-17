#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <memory>

using size_type = int;

template < typename T >
class Vector{
	private:
		size_type vSize;
		T *vector;

	public:
		Vector< T > ( int _size = 0 ) : vSize( _size ), vector( new T[vSize] ){/* Empty */}
		size_type size() const;
		void clear();
		bool empty();
		void push_back( const T & x );		
		void pop_back();
		const T & back() const;
};

#include "Vector.inl"

#endif