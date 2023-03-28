#include <iostream>
#include "PilhaC.h"

int main(void) {
	int n;
	Pilha pilhaPar = criapilha(5);
	Pilha pilhaImpar = criapilha(5);
	for (int i = 0; i < 5;i++) {
		cout << "Entre com o numero ";
		cin >> n;
		if (n % 2 == 0) {
			push(pilhaPar, n);
		}
		else {
			push(pilhaImpar, n);
		}
	}
	cout << "Pilhas pares : ";
	while (!isEmpty(pilhaPar)) {
		cout << pop(pilhaPar) << " ";
	}
	cout << "Pilhas impares : ";
	while (!isEmpty(pilhaImpar)) {
		cout << pop(pilhaImpar) << " ";
	}
	
}