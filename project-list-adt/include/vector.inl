template < typename T >
size_type Vector< T >::size() const{
	return vSize;
}

template < typename T >
void Vector< T >::clear(){
	vSize = 0;
	delete [] vector;
}

template < typename T >
bool Vector< T >::empty(){
	return vSize == 0;
}

template < typename T >
void Vector< T >::push_back( const T & x ){
	//try
	//catch?
	vector[vSize] = x;
	vSize++;
}

template < typename T >
void Vector< T >::pop_back(){
	vSize--;
}

template < typename T >
const T & Vector< T >::back() const{
	return vector[vSize-1];
}