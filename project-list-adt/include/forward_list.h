/*!
 *  @file Forward_list.h
 *  @brief Forward List ADT
 *  @copyright Copyright &copy; 2016. Todos os direitos reservados.
 *
 *  Arquivo que contêm a foward list
 */


#ifndef FORWARD_LIST_H
#define FORWARD_LIST_H

using size_type = int;

template < typename T >
class Forward_list{
	private:
	struct Node {        //!< Struct para um nó de lista encadeada
		T data;        //!< Armazena os interios da lista
		Node *next;  //!< Aponta para o poróximo nó da lista
 	 	Node( const T & d = T(), Node *n = nullptr) : data (d), next (n){/* Empty */}
	};
	
	size_type m_size;
	Node *m_head;
	Node *m_tail;

	public:
	
	/**
 	 * @brief Construtor Foward List
 	 */
	Forward_list ();
	
	/**
 	 * @brief Destrutor Foward List
 	 */
	~Forward_list();
	
	/**
 	 * @brief Retorna o tamanho atual da lista
 	 * @return Tamanho da lista
 	 */
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
     * @brief Adiciona um valor ao final da lista
     * @param x é o elemento à ser movido
     */
	void push_back( const T & x );
	
	/**
 	 * @brief Retira um elemento do fim da lista
 	 * @return O elemento retirado
 	 */
	T pop_back();
	
	
	const T & back() const;
	
	/**
     * @brief Substitui os elementos da lista por um determinado valor
     * @param x, valor para ser usado na substituição
     */
	void assign( const T & x );
	
	// Exclusive
	
	/**
     * @brief Adiciona um valor ao começo da lista
     * @param x é o elemento à ser movido
     */
	void push_front( const T & x );
	
	/**
 	 * @brief Retira um elemento da frente da lista
 	 * @return O elemento retirado
 	 */
	T pop_front();
	
	/**
 	 * @brief Retorna o elemento na frente da lista
 	 * @return O elemento retirado
 	 */
	const T & front () const;
};

#include "forward_list.cpp"

#endif