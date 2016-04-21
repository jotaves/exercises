#include "queuear.h"

int main(){
	QueueAr< char > queue(5);
	cout << "\n>>> This visualization will show the queue as a 'real' queue, not how the queue really is inside the class.\n\n";
	
	cout << "Is empty: " << queue.isEmpty() << endl;
	cout << queue << endl << endl;

	cout << "Adding numbers from 0 to 4...\n";
	queue.enqueue('0');
	queue.enqueue('1');
	queue.enqueue('2');
	queue.enqueue('3');
	queue.enqueue('4');
	cout << queue << " Get front: " << queue.getFront() << endl;
	cout << "Is empty: " << queue.isEmpty() << endl << endl;

	cout << "Removing 1st and 2nd...\n";
	queue.dequeue();
	queue.dequeue();
	cout << queue << " Get front: " << queue.getFront() << endl << endl;

	cout << "Adding 0 and 1 at the end...\n";
	queue.enqueue('0');
	queue.enqueue('1');
	cout << queue << endl << endl;

	cout << "Removing from the start and adding at the end...\n";
	queue.dequeue();
	queue.enqueue('2');
	cout << queue << endl;

	queue.dequeue();
	queue.enqueue('3');
	cout << queue << endl;

	queue.dequeue();
	queue.enqueue('4');
	cout << queue << endl << endl;

	cout << "Calling makeEmpty()...\n\n";
	queue.makeEmpty();
	cout << "Is empty: " << queue.isEmpty() << endl << endl;

	cout << "Adding numbers from 0 to 9...\n";
	queue.enqueue('0');
	queue.enqueue('1');
	queue.enqueue('2');
	queue.enqueue('3');
	queue.enqueue('4');
	queue.enqueue('5');
	queue.enqueue('6');
	queue.enqueue('7');
	queue.enqueue('8');
	queue.enqueue('9');	
	cout << queue << endl << endl;

	cout << "Removing from the start and adding at the end...\n";
	queue.dequeue();
	queue.enqueue('0');
	cout << queue << " Get front: " << queue.getFront() << endl;

	queue.dequeue();
	queue.enqueue('1');
	cout << queue << endl;

	queue.dequeue();
	queue.enqueue('2');
	cout << queue << endl;

	queue.dequeue();
	queue.enqueue('3');
	cout << queue << " Get front: " << queue.getFront() << endl;

	queue.dequeue();
	queue.enqueue('4');
	cout << queue << endl;

	queue.dequeue();
	queue.enqueue('5');
	cout << queue << endl;
	
	queue.dequeue();
	queue.enqueue('6');
	cout << queue << " Get front: " << queue.getFront() << endl;

	queue.dequeue();
	queue.enqueue('7');
	cout << queue << endl;

	queue.dequeue();
	queue.enqueue('8');
	cout << queue << endl;

	queue.dequeue();
	queue.enqueue('9');
	cout << queue << " Get front: " << queue.getFront() << endl << endl;

	cout << "Adding a and b...\n";
	queue.enqueue('a');
	queue.enqueue('b');
	cout << queue << endl << endl;

	cout << "Adding letters from c to o...\n";
	queue.enqueue('c');
	queue.enqueue('d');
	queue.enqueue('e');
	queue.enqueue('f');
	queue.enqueue('g');
	queue.enqueue('h');
	queue.enqueue('i');
	queue.enqueue('j');
	queue.enqueue('k');
	queue.enqueue('l');
	queue.enqueue('m');
	queue.enqueue('n');
	queue.enqueue('o');

	cout << "\nFinal queue: \n" << queue << " Get front: " << queue.getFront() << "\n\n";
	return 0;
}