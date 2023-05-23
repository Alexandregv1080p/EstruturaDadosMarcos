#pragma once
#include <iostream>
#include <string>
using namespace std;
class Lista {
	private:
		struct No {
			char info;
			No* prox;
		}*L;
		int TAM;
	public:
		Lista() { L = NULL; TAM = 0; }
		void insere(char x);
		void inseresr(char x);
		int tamanho() { return TAM; };
		void mostra();
		string mostra2();
		int conta(char);
};
void Lista::insere(char x) {
	No** pL = &L;
	while (*pL != NULL and x >= (*pL)->info) {
		pL = &(*pL) -> prox;
	}
	No* aux = new No();
	aux->info = x;
	aux->prox = *pL;
	*pL = aux;
	TAM++;
}
void Lista::mostra() {
	cout << "[";
	No* pL = L;
	while (pL) {
		cout << pL->info;
		if (pL->prox) cout << ",";
		pL = pL->prox;
	}
	cout << "]";
}
string Lista::mostra2() {
	string s = "[";
	No* pL = L;
	while (pL) {

		s += pL->info;
		if (pL->prox) s+= ",";
		pL = pL->prox;

	}
	s += "]";
	return s;
}
void Lista::inseresr(char x) {
	No** pL = &L;
	while (*pL != NULL and x > (*pL)->info) {
		pL = &(*pL)->prox;
	}
	if (*pL != NULL and x == (*pL)->info) return;
	No* aux = new No();
	aux->info = x;
	aux->prox = *pL;
	*pL = aux;
	TAM++;
}
int Lista::conta(char x) {
	No* pL = L;
	int num = 0;
	while (pL) {
		if (pL->info == x) num++;
		pL = pL->prox;

	}
	return num;
}