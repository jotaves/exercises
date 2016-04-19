#include "stackint.cpp"

int main(){
	StackInt stack( 0 );

	stack.push(1);
	stack.push(2);
	stack.push(3);
	stack.push(4);
	stack.push(4);
	stack.push(1);

	cout << stack << endl;

	cout << "Top: " << stack.top() << endl;

	cout << "Pop: " << stack.pop() << endl;

	cout << "Top: " << stack.top() << endl;

	cout << stack << endl;

	cout << "Pop: " << stack.pop() << endl;
	cout << "Pop: " << stack.pop() << endl;
	cout << "Pop: " << stack.pop() << endl;
	cout << "Pop: " << stack.pop() << endl;
	cout << "Pop: " << stack.pop() << endl;
	//cout << "Pop: " << stack.pop() << endl; //ERROR

	cout << stack << endl;
	//cout << "Top: " << stack.top() << endl; //ERROR

	return 0;
}