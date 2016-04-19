#include "stackar.h"

int main(){
	StackAr< char > stack;

	stack.push('1');
	stack.push('2');
	stack.push('3');
	stack.push('4');

	cout << stack << endl;

	cout << "Is empty: " << stack.isEmpty() << endl;

	cout << "Pop: " << stack.pop() << endl;

	cout << "Top: " << stack.top() << endl;

	stack.makeEmpty();
	cout << "Stack cleaned. " << endl;

	cout << stack << endl;
	cout << "Is empty: " << stack.isEmpty() << endl;

	stack.push('1');

	cout << stack << endl;
	cout << "Is empty: " << stack.isEmpty() << endl;
	cout << "Top: " << stack.top() << endl;
	cout << "Pop: " << stack.pop() << endl;
	cout << "Is empty: " << stack.isEmpty() << endl;	

	return 0;
}