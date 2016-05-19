/*!
 *  @file forward_list.h
 *  @brief Forward List ADT
 *  @copyright Copyright &copy; 2016. Todos os direitos reservados.
 *
 *  Arquivo que contêm a foward list
 */


#ifndef FORWARD_LIST_H
#define FORWARD_LIST_H

using size_type = int;

template < typename T >
class Forward_List{
	private:
	struct Node {        // Struct for a Single Linked List Node.
		T data;        // List stores integers.
		Node *next;  // Points to next node in list.
 	 	Node( const T & d = T(), Node *n = nullptr) : data (d), next (n){}
	};
	
	size_type m_size;
	Node *m_head;
	Node *m_tail;

	public:
	Forward_List (); 
	~Forward_List();
	size_type size() const;
	void clear();
	bool empty();
	void push_back( const T & x );		
	T pop_back();
	const T & back() const;
	void assign( const T & x );
	
	// Exclusive
	void push_front( const T & x );
	T pop_front();
};

#include "forward_list.cpp"

#endif
