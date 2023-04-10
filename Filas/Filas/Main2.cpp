#include <iostream>
#include "Fila.h"

using namespace std;

int main(void) {
	Fila Fnormal = criaFila(10);
	Fila Fpreferencial = criaFila(10);
	int op, count = 0;

	string nome;
	do {
		cout << "----- Programa para inserção de filas -----" << endl;
		cout << "----- 1 - Inserir na fila normal -----" << endl;
		cout << "----- 2 - Inserir na fila de prioridades -----" << endl;
		cout << "----- 3 - Remover -----" << endl;
		cin >> op;
		if (op == 1) {
			cout << "Entre com o nome que deseja inserir na fila : ";
			cin >> nome;
			if (count == 3) {
				enqueue(Fpreferencial, nome);
				cout << "Inserindo na fila preferencial, pois e o terceiro... " << endl;
				count = 0;
			}
			else{
				enqueue(Fnormal, nome);
				cout << "Inserindo na fila normal... " << endl;
				count++;
			}
		}else if (op == 2) {
				cout << "Entre com o nome que deseja inserir no preferencial : ";
				cin >> nome;
				enqueue(Fpreferencial, nome);
				count++;
			}
		else if (op == 3) {
			if (!isEmpty(Fpreferencial)) {
				cout << "Item removido : " << dequeue(Fpreferencial) << endl;
			}
			else if (!isEmpty(Fnormal)) {
				cout << "Item removido : " << dequeue(Fnormal) << endl;
			}
		}
	} while (op != 4);

	return 1;
}
