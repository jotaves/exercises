
#include "queuear.h"

int main(){
	QueueAr< int > queue(5);
	cout << "\n>>> This visualization will show the queue as a 'real' queue, not how the queue really is inside the class.\n\n";
	
	cout << "Is empty: " << queue.isEmpty() << endl;
	cout << queue << endl;

	queue.enqueue(6);
	queue.enqueue(6);
	queue.enqueue(6);
	queue.enqueue(6);
	queue.enqueue(6);
	cout << queue << endl;
	cout << "Is empty: " << queue.isEmpty() << endl;

	queue.dequeue();
	queue.dequeue();
	cout << queue << endl;

	queue.enqueue(1);
	queue.enqueue(2);
	cout << queue << endl;

	queue.dequeue();
	queue.enqueue(3);
	cout << queue << endl;

	queue.dequeue();
	queue.enqueue(4);
	cout << queue << endl;

	queue.dequeue();
	queue.enqueue(5);
	cout << queue << endl;

	cout << "Calling makeEmpty...\n";
	queue.makeEmpty();
	cout << "Is empty: " << queue.isEmpty() << endl;

	queue.enqueue(6);
	queue.enqueue(6);
	queue.enqueue(6);
	queue.enqueue(6);
	queue.enqueue(6);
	queue.enqueue(6);
	queue.enqueue(6);
	queue.enqueue(6);
	queue.enqueue(6);
	cout << queue << endl;

	queue.dequeue();	
	queue.enqueue(1);
	cout << queue << endl;

	queue.dequeue();
	queue.enqueue(2);
	cout << queue << endl;

	queue.dequeue();
	queue.enqueue(3);
	cout << queue << endl;

	queue.dequeue();
	queue.enqueue(4);
	cout << queue << endl;

	queue.dequeue();
	queue.enqueue(5);
	cout << queue << endl;

	queue.dequeue();
	queue.enqueue(6);
	cout << queue << endl;

	queue.dequeue();
	queue.enqueue(7);
	cout << queue << endl;

	queue.dequeue();
	queue.enqueue(8);
	cout << queue << endl;

	queue.dequeue();
	queue.enqueue(9);
	cout << queue << endl;

	queue.enqueue(10);
	queue.enqueue(11);
	cout << queue << endl;
	queue.enqueue(12);
	// ERROR :/
	cout << queue << endl;
	return 0;
}