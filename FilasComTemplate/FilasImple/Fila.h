#pragma once
#include <iostream>

template <class Elem>
class Fila {
private:
	int tam;
	struct no {
		Elem content;
		no* prox;
	};
	no* inicio;
	no* fim;
public:
	Fila();
	bool isEmpty();
	void enqueue(Elem item);
	Elem dequeue();
};
	template <class Elem>
	bool Fila<Elem>::isEmpty() {
		return (tam == 0);
	};
	template <class Elem>
	void Fila<Elem>::enqueue(Elem item) {
		no* aux = new no;
		aux->content = item;
		aux->prox = NULL;
		if (isEmpty()) {
			inicio = aux;
			fim = aux;
		}
		else {
			fim->prox = aux;
			fim = aux;
		}
		tam++;
	};
	template <class Elem>
	Elem Fila<Elem>::dequeue() {
		if (!isEmpty()) {
			tam--;
			Elem item = inicio->content;
			no* aux = inicio;
			inicio = aux->prox;
			delete aux;
			return item;
		}
	};

	template <class Elem>
	Fila<Elem>::Fila() {
		tam = 0;
		inicio = NULL;
		fim = NULL;
	};