#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <memory> // necessary for unique pointer

using size_type = int;

template < typename T >
class Vector{
public:
	Vector< T > ( int _size = 1 ) : vSize( _size ), vector( new T[vSize] ){/* Empty */}
	size_type size() const;
	void clear();
	bool empty();
	void push_back( const T & x );		
	void pop_back();
	const T & back() const;
	const void multiply();

private:
	size_type vSize;
	size_type lastPos = 0;
	std::unique_ptr<T[]> vector; // try to use unique pointer after

};

#include "vector.inl"

#endif