/*!
 *  @file vector.h
 *  @brief Vector ADT
 *  @copyright Copyright &copy; 2016. Todos os direitos reservados.
 *
 *  File with the Vector ADT header
 */

#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <memory>

using size_type = int;

template < typename T >
class Vector{
public:
	class const_iterator{
	public:
		const_iterator();
		
		const T & operator* () const;
		
		 //++it
		const_iterator & operator++ ();
		
		 //it++
		const_iterator operator++ (int);
		
		 //--it
		const_iterator & operator-- ();
		
		 //it--
		const_iterator operator-- (int);
		
		bool operator == (const const_iterator & rhs) const;
		
		bool operator != (const const_iterator & rhs) const;
		
	private:
		T *p = nullptr;
		const_iterator (T *_p) : p(_p){/* Empty */}
		friend class Vector<T>;
	};

	class iterator: public const_iterator{
	public:
		iterator() : const_iterator(){/* Empty */}
		
		T & operator * (){
			return *const_iterator::p;
		}
		
	protected:
		iterator (T *_p = nullptr) : const_iterator(_p){/* Empty */}
		friend class Vector<T>;
	};


	/* Common functions */
	
	
	Vector< T > ( int _size = 0 ) : _capacity( _size ), vector( new T[_capacity] ){/* Empty */}
	~Vector(){/* Empty */};
	size_type size() const;
	
	/**
     * @brief Remove todos os elementos do container
     */
	void clear();
	
	/**
     * @brief Verifica se o container possui elementos
     * @return True se estiver vazio, caso contrário, false
     */
	bool empty();
	
	/**
     * @brief Adiciona um valor ao final do vetor
     * @param x é o elemento à ser movido
     */
	void push_back( const T & x );	
	
	/**
     * @brief Remove o elemento no final da lista
     */
	void pop_back();
	
	/**
     * @brief Retorna o elemento que estiver no final da lista
     * @return O último elemento da lista
     */
	const T & back() const;
	
	/**
     * @brief Substitui os elementos da lista por um determinado valor
     * @param x, valor para ser usado na substituição
     */
	void assign( const T & x );
	
	
	/* Exclusive functions */
	
	
	/**
     * @brief Sobrecarrega o operador []
     * @param idx, é a posição à ser acessada
     * @return O objeto que está na posição informada
     */
	T & operator[]( size_type idx);
	
	/**
     * @brief Retona o elemento em alguma posição
     * @param idx, posição a ser retornada
     * @return O objeto que está na posição informada
     */
	T & at ( size_type idx );
	
	/**
     * @brief Retorna a capacidade do vetor
     * @return Capacidade do vector
     */
	size_type capacity() const;
	
	/**
     * @brief Atualiza a capacidade do vector
     * @param newSize, nova capacidade do vector
     */
	const void reserve(size_type newSize);
	
	/* Return iterators */
    const_iterator cbegin() const;
    const_iterator cend() const;
    iterator begin() const;
    iterator end() const;
	
private:
	size_type _capacity; //!< Capacidade do vector
	size_type lastPos = 0; //!< Posição do último elemento
	std::unique_ptr<T[]> vector; //!< Ponteiro inteligente para o vector

};

#include "vector.cpp"

#endif