template < typename T >
size_type Vector< T >::size() const{
	return lastPos;
}

template < typename T >
void Vector< T >::clear(){
	vector = nullptr;
	vSize = 0;
	lastPos =  0;
}

template < typename T >
bool Vector< T >::empty(){
	return lastPos == 0;
}

template < typename T >
const void Vector< T >::multiply(){
	auto newSize(0);
	if (vSize == 0) newSize = 1;
	else newSize = vSize * 2;

	std::unique_ptr<T[]> _vector (new T[newSize]);
	for(auto i(0); i < vSize; i++){
		_vector[i] = vector[i];
	}

	vector = std::move(_vector);
	vSize = newSize;
}

template < typename T >
void Vector< T >::push_back( const T & x ){
	if(lastPos == vSize) multiply();
	vector[lastPos++] = x;
}

template < typename T >
void Vector< T >::pop_back(){
	if(lastPos == 0) vector = nullptr;
	else lastPos--;
}

template < typename T >
const T & Vector< T >::back() const{
	return vector[lastPos-1];
}