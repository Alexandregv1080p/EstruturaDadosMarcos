#pragma once

typedef char Elem;
typedef struct fila {
	int Tam;
	int Total;
	int Inicio, Final;
	Elem* M;
}*Fila;

Fila criaFila(int n) {
	Fila F = new fila;
	F->Tam = n;
	F->Inicio = F->Final = F->Total = 0;
	F->M = new Elem[n];
	return F;
}
void enqueue(Fila F,Elem x) {
	if (F->Total < F->Tam) {
		F->M[F->Final] = x;
		F->Total++;
		F->Final++;
		if (F->Final == F->Tam) {
			F->Final = 0;
		}
	}
}
Elem dequeue(Fila F) {
	if (F->Total > 0) {
		Elem x = F->M[F->Inicio];
		F->Total--;
		F->Inicio++;
		if(F->Inicio == F->Tam) {
			F->Inicio = 0;
		}
		return x;
	}

}
char isEmpty(Fila f) {
	return !f->Total;
}