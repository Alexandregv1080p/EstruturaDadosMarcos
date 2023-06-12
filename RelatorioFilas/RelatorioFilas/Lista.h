#pragma once
#include <iostream>
#include <string>

using namespace std;
template <class Elem>
class Lista {
private:
	struct No {
		Elem info;
		int nr;
		No* prox;
	}*L;
	int TAM;
public:
	Lista() { L = NULL; TAM = 0; }
	void insere(Elem x, int);
	void mostra();
	char remove(Elem x);
	int	*registros();
};
template <class Elem>
void Lista<Elem>::insere(Elem x, int nr) {
	No** pL = &L;
	while (*pL != NULL and x >= (*pL)->info) {
		pL = &(*pL)->prox;
	}
	No* aux = new No();
	aux->info = x;
	aux->nr = nr;
	aux->prox = *pL;
	*pL = aux;
	TAM++;
}
template <class Elem>
void Lista<Elem>::mostra() {
	cout << "[";
	No* pL = L;
	while (pL) {
		cout << pL->info;
		if (pL->prox) cout << ",";
		pL = pL->prox;
	}
	cout << "]";
}
template <class Elem>
int *Lista<Elem>::registros() {
	int* vet = new int[TAM];
	No* aux = L;
	for(int i = 0; i < TAM; i++) {
		vet[i] = aux->prox;
		aux = aux->prox;
	}
	return vet;

}
template <class Elem>
char Lista<Elem>::remove(Elem x) {
	if (L and x == L->info) {
		No* aux = L;
		L = L->prox;
		delete aux;
		TAM--;
		return 1;
	}
	No* pL = L;
	while (pL->prox and x > pL->prox->info) {
		pL = pL->prox;
	}
	if (pL->prox and x == pL->prox->info) {
		No* aux = pL->prox;
		pL->prox = aux->prox;
		delete aux;
		TAM--;
		return 1;
	}
	return 0;
}