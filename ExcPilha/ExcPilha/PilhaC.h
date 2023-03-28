#pragma once
#include <iostream>
using namespace std;

typedef int Elem;
typedef struct pilha {
	int tam;
	int topo;
	Elem* M;
} *Pilha;

Pilha criapilha(int n) {
	Pilha aux = new pilha;
	aux->tam = n;
	aux->topo = 0;
	aux->M = new Elem[n];
	return aux;
}
bool isEmpty(Pilha p) {
	return p->topo == 0;
}
bool isFull(Pilha p) {
	return p->tam == p->topo;
}
void push(Pilha p, Elem x) {
	if (!isFull(p)) {
		p->	M[p->topo] = x;
		p->topo++;
	}
}
Elem top(Pilha p) {
	if (!isEmpty(p)) {
		return p->M[p->topo - 1];
	}
}
Elem pop(Pilha p) {
	if (!isEmpty(p)) {
		p->topo--;
		return p->M[p->topo];
	}
}