#include "FilasO.h"
#include <iostream>
#include <string>
int main() {
	Lista* L1 = new Lista();
	L1->insere('c');
	L1->insere('e');
	L1->insere('h');
	L1->insere('a');
	L1->insere('a');
	L1->insere('a');
	L1->insere('a');
	cout << L1->mostra2();
	cout << L1->conta('a');
}