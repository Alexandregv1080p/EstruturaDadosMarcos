#include <iostream>
#include "PilhaC.h"

int main(void){
	int n = 0,maior = 0,menor = 0;
	Pilha pilhaA = criapilha(5);
	Pilha pilhaB = criapilha(5);
	for (int i = 0; i < 5; i++) {
		cout << "Entre com o " << i + 1 << "numero " << endl;
		cin >> n;
		if (n > top(pilhaA)) {
			push(pilhaA, n);
		}
		else {
			push(pilhaB, n);
		}
	}
	while (!isEmpty(pilhaA)) {
		cout << pop(pilhaA) << " ";
	}
	while (!isEmpty(pilhaB)) {
		cout << pop(pilhaB) << " ";
	}
	
}

