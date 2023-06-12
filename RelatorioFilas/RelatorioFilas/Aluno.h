#pragma once
#include <iostream>
#include <fstream>
#include "Lista.h"

using namespace std;

class Aluno {
	struct aluno {
		char flag;
		char nome[30];
		float n1, n2;
	};
	public:
		void cadastrar(fstream *arq);
		int tamanho(fstream *arq);
		void consulta(fstream *arq);
		void excluir(fstream* arq);
		void diario(fstream* arq);
};
int Aluno::tamanho(fstream* arq){
	arq->seekg(0, ios::end);
	return arq->tellg() / sizeof(aluno);
};
void Aluno::cadastrar(fstream* arq) {
	aluno reg;
	cout << "Cadastrando registro No: " << tamanho(arq) + 1;
	cout << "Nome: ";
	cin >> reg.nome;
	cout << "Nota 1: ";
	cin >> reg.n1;
	cout << "Nota 1: ";
	cin >> reg.n2;
	reg.flag = '-';
	char conf;
	do {
		cout << "Confirma? <S/N>: ";
		conf = toupper(conf);
		cin >> conf;
	} while (conf != 'S' and conf != 'N');
	if (conf == 'S') {
		arq->seekp(0, ios::end);
		arq->write((const char*)&reg, sizeof(aluno));
		arq->flush();
		cout << "Registro gravado com sucesso! \n";
		system("pause");
	}

};
void Aluno::consulta(fstream* arq) {
	int nr;
	cout << "Entre com o numero do registo: ";
	cin >> nr;
	if (nr <= tamanho(arq)) {
		aluno reg;
		arq->seekg((nr - 1) * sizeof(aluno));
		arq->read((char*)&reg, sizeof(aluno));
		cout << "Nome: " << reg.nome << endl;
		cout << "Nota 1: " << reg.n1 << endl;
		cout << "Nota 2: " << reg.n2 << endl;
		cout << "Media: " << (reg.n1 + reg.n2) / 2 << endl;
		system("pause");
	}
};
void Aluno::excluir(fstream* arq) {
	int nr;
	cout << "Entre com o numero do registo: ";
	cin >> nr;
	aluno reg;
	if (nr <= tamanho(arq)) {
		arq->seekg((nr - 1) * sizeof(aluno));
		arq->read((char*)&reg, sizeof(aluno));
		cout << "Nome: " << reg.nome << endl;
		cout << "Nota 1: " << reg.n1 << endl;
		cout << "Nota 2: " << reg.n2 << endl;
		cout << "Media: " << (reg.n1 + reg.n2) / 2 << endl;
	}
	char conf;
	do {
		cout << "Confirma? <S/N>";
		conf = toupper(conf);
		cin >> conf;
	} while (conf != 'S' and conf != 'N');
	if (conf == 'S') {
		reg.flag = '*';
		arq->seekp((nr - 1) * sizeof(aluno));
	}
};
void Aluno::diario(fstream* arq) {
	Lista<string> L;
	aluno reg;
	string x;
	int nr = 0;
	arq->seekg(0, ios::beg);
	arq->read((char*)&reg, sizeof(aluno));
	while (!arq->eof()) {
		x = reg.nome;
		L.insere(x, nr);
		nr++;
		arq->read((char*)&reg, sizeof(aluno)); //ler o proximo
	}
	arq->clear();
	int* regs = L.registros();

}