/**Classe interface pilha (não pode ser instanciada!). */
template< class Object >
class AbsStack {
	public:
		// Default constructor
		AbsStack ( void ) { /* Empty */ }

		// Default destructor
		virtual ~AbsStack( void ) { /* Empty */ }

		// Basic members
		virtual void push ( const Object & ) = 0;
		virtual Object pop ( void ) = 0;
		virtual Object top ( void ) const = 0;
		virtual bool isEmpty ( void ) const = 0;
		virtual void makeEmpty ( void ) = 0;

	private:
		// Disable copy constructor
		AbsStack ( const AbsStack & ) { /* Empty */ }
};