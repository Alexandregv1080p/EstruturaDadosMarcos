#include <iostream>
#include "PilhaC.h"
using namespace std;
int main(void) {
	Pilha pilha1 = criapilha(5);
	/*push(pilha1, 5);
	push(pilha1, 7);
	cout << top(pilha1) << endl;
	pop(pilha1);
	cout << top(pilha1) << endl;*/
	int n;
	cout << "Entre com um valor : ";
	cin >> n;
	while (n > 0) {
		if (!isFull(pilha1)) {
			push(pilha1, n % 2);
			n = n / 2;
		}
		else
		{
			cout << "Estouro!";
		}
	}
	while (!isEmpty(pilha1)) {
		cout << pop(pilha1);
	}
}