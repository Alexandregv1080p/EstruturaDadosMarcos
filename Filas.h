#pragma once
#include <iostream>
typedef char Elem;
const int max_itens = 100;

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
		Fila() {
			tam = 0;
			inicio = NULL;
			fim = NULL;
		};
		bool isEmpty(){
			return (tam == 0);
		};
		void enqueue(Elem item) {
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
		Elem dequeue() {
			if (!isEmpty()) {
				tam--;
				Elem item = inicio->content;
				no* aux = inicio;
				inicio = aux->prox;
				delete aux;
				return item;
			}
		};
		bool empty() {
			tam;
		}
};