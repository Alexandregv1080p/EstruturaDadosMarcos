#include <iostream>
#include"Fila.h"
using namespace std;

int main(void) {
	Fila<char>* F1 = new Fila<char>();
	F1->enqueue('M');
	F1->enqueue('A');
	F1->enqueue('C');

	cout << F1->dequeue() << endl;
	cout << F1->dequeue() << endl;
	cout << F1->dequeue() << endl;

	Fila<int>* F2 = new Fila<int>();
	F2->enqueue(20);
	F2->enqueue(10);
	F2->enqueue(145);

	cout << F2->dequeue() << endl;
	cout << F2->dequeue() << endl;
	cout << F2->dequeue() << endl;

}

