/*!
 *  @file vector.inl
 *  @brief Implementações do vetor
 *  @copyright Copyright &copy; 2016. Todos os direitos reservados.
 *
 *  @Arquivo com as implementações do vecotr ADT.
 */

/* Common functions */
template < typename T >
size_type Vector< T >::size() const{
	return lastPos;
}

template < typename T >
void Vector< T >::clear(){
	while (lastPos > 0){
		(&vector[--lastPos])->~T();
	}
}

template < typename T >
bool Vector< T >::empty(){
	return lastPos == 0;
}

template < typename T >
void Vector< T >::push_back( const T & x ){
	if(lastPos == _capacity){
		if (_capacity == 0) reserve(1);
		else reserve(_capacity*2);
	}
	vector[lastPos++] = x;
}

template < typename T >
void Vector< T >::pop_back(){
	if (lastPos == 0) (&vector[lastPos])->~T();
	else (&vector[--lastPos])->~T();
}

template < typename T >
const T & Vector< T >::back() const{
	return vector[lastPos-1];
}

template < typename T >
void Vector< T >::assign( const T & x ){
	lastPos = 0;
	while(lastPos < _capacity){
		vector[lastPos++] = x;
	}
}

/* Exclusive functions */
template < typename T >
T & Vector< T >::operator[]( size_type idx ){
	return vector[idx];
}

template < typename T >
T & Vector< T >::at ( size_type idx ){
	if(idx < 0 or idx > lastPos-1){
		throw std::out_of_range ("[Vector< T >at]: index used is out of range.");
	}
	else return vector[idx];
}

template < typename T >
size_type Vector< T >::capacity() const{
	return _capacity;
}

template < typename T >
const void Vector< T >::reserve(size_type newSize){
	std::unique_ptr<T[]> _vector (new T[newSize]);
	
	for(size_type i(0); i < lastPos; i++){
		_vector[i] = vector[i];
	}

	vector = std::move(_vector);
	_capacity = newSize;
}

/* Return iterators */
template < typename T >
typename Vector< T >::const_iterator Vector< T >::cbegin() const{
	return const_iterator(&vector[0]);
}

template < typename T >
typename Vector< T >::const_iterator Vector< T >::cend() const{
	return const_iterator(&vector[lastPos-1]);
}

template < typename T >
typename Vector< T >::iterator Vector< T >::begin() const{
	return iterator(&vector[0]);
}

template < typename T >
typename Vector< T >::iterator Vector< T >::end() const{
	return iterator(&vector[lastPos-1]);
}

/* Iterators classes functions */
template < typename T >
const T & Vector< T >::const_iterator::operator* () const{
	return *p;
}

template < typename T >
typename Vector< T >::const_iterator & Vector< T >::const_iterator::operator++ (){
	++p;
	return *this;
}

template < typename T >
typename Vector< T >::const_iterator Vector< T >::const_iterator::operator++ (int){
	const_iterator np (p++);
	return np;
}

template < typename T >
typename Vector< T >::const_iterator & Vector< T >::const_iterator::operator-- (){
	p--;
	return *this;
}

template < typename T >
typename Vector< T >::const_iterator Vector< T >::const_iterator::operator-- (int){
	const_iterator np (p--);
	return np;
}

template < typename T >
bool Vector< T >::const_iterator::operator == (const const_iterator & rhs) const{
	return p == rhs.p;
}

template < typename T >
bool Vector< T >::const_iterator::operator != (const const_iterator & rhs) const{
	return p != rhs.p;
}