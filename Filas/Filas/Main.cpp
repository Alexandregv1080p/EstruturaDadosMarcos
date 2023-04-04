#include <iostream>
#include "Fila.h"

using namespace std;

int main(void) {
	Fila F;
	F = criaFila(5);
	enqueue(F, 'a');
	enqueue(F, 'b');
	enqueue(F, 'c');
	enqueue(F, 'd');
	enqueue(F, 'e');

	while (!isEmpty(F)) {
		cout << dequeue(F) << " ";
	}
	
	return 1;
}