#include <iostream>
#include "Fila.h"
#include <Windows.h>
using namespace std;

HANDLE Console = GetStdHandle(STD_OUTPUT_HANDLE);

#define dim 9
int I[dim][dim] =
{
	{0,0,0,0,0,0,0,0,0},
	{0,0,0,0,1,0,0,0,0},
	{0,0,0,1,1,1,0,0,0},
	{0,0,1,1,1,1,1,0,0},
	{0,1,1,1,1,1,1,1,0},
	{0,0,2,0,0,0,2,0,0},
	{0,0,2,0,0,0,2,0,0},
	{0,0,2,2,2,2,2,0,0},
	{0,0,0,0,0,0,0,0,0}
};
void mostra() {
	for (int i = -1; i < dim; i++) {
		SetConsoleTextAttribute(Console, 15);
		for (int j = -1; j < dim; j++) {
			if (i < 0 && j < 0) printf("  ");
			else if (i < 0) printf("%2d", j);
			else if (j < 0) printf("\n%2d", i);
			else {
				SetConsoleTextAttribute(Console, I[i][j]);
				printf("%c%c", 219, 219);
			}
		}
		SetConsoleTextAttribute(Console, 15);
	}
}
int par(int i, int j) {
	return i * 100 + j;
}
int cor(int i, int j) {
	if (i >= 0 and j >= 0 and i < dim and j < dim) {
		return I[i][j];
	}
	else {
		return -1;
	}
}
int linha(int p) {
	return p / 100;
}
int coluna(int p) {
	return p % 100;
}
void colorir(int i, int j, int n) {
	Fila F = criaFila(dim * dim);
	int p,a = I[i][j];
	I[i][j] = n;
	enqueue(F, par(i, j));
	while (not isEmpty(F)) {
		p = dequeue(F);
		i = linha(p);
		j = coluna(p);
		if (cor(i - 1,j ) == a) {
			I[i - 1][j] = n;
			enqueue(F, par(i - 1, j));
		}
		if (cor(i, j + 1) == a) {
			I[i][j + 1] = n;
			enqueue(F, par(i, j + 1));
		}
		if (cor(i + 1, j) == a) {
			I[i + 1][j] = n;
			enqueue(F, par(i + 1, j));
		}
		if (cor(i, j - 1) == a) {
			I[i][j - 1] = n;
			enqueue(F, par(i, j - 1));
		}
	}
}

int main(void) {
	int n, i, j;
	do {
		system("cls");
		mostra();
		cout << "\nNova cor (-1 para): ";
		cin >> n;
		if (n != -1) {
			cout << "Entre com X e Y:";
			cin >> i >> j;
		}
		colorir(i, j, n);
	} while (n != -1);
}