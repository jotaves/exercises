#ifndef ABSQUEUE_H
#define ABSQUEUE_H

/**Classe interface fila (não pode ser instanciada!). */
template < class Object >
class AbsQueue {
	public:
		AbsQueue ( void ) { /* Empty */ } // Default constructor
		virtual ~AbsQueue( void ) { /* Empty */ } // Default destructor

		// Basic members
		virtual void enqueue ( const Object & x ) = 0;
		virtual Object dequeue ( void ) = 0;
		virtual Object getFront ( void ) const = 0;
		virtual bool isEmpty ( void ) const = 0;
		virtual void makeEmpty ( void ) = 0;

	private:
		// Disable copy constructor
		AbsQueue ( const AbsQueue & ) { /* Empty */ }
};

#endif