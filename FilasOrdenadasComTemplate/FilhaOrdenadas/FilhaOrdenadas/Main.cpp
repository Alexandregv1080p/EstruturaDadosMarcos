#include "FilasO.h"
#include <iostream>
#include <string>
using namespace std;
int main() {
	Lista<char>* L1 = new Lista<char>();
	L1->insere('c');
	L1->insere('e');

	L1->mostra();

	Lista<int>* L2 = new Lista<int>();
	L2->insere(1);
	L2->insere(2);
	L2->insere(3);

	L2->mostra();

	Lista<float>* L3 = new Lista<float>();
	L3->insere(1.5);
	L3->insere(2.6);
	L3->insere(1.2);

	L3->mostra();

	Lista<string>* L4 = new Lista<string>();
	L4->insere("Teste");
	L4->insere("Teste 1");
	L4->insere("Teste 2");

	L4->mostra();
	
}