#include <iostream>
#include <string>
#include <sstream>
#include <array>

using namespace std;
using sudoku = array<array<int, 9>, 9>;

bool check(const sudoku& jogo, int valor, int bLinha, int bCol);
void jogoAtual(sudoku& jogo);
void printJogo(const sudoku& jogo);
bool GiO(const sudoku& jogo);

int main() {
	sudoku jogo = { {
		{0, 0, 0, 1, 5, 0, 0, 0, 0},
		{0, 0, 0, 8, 9, 4, 0, 6, 2},
		{9, 0, 8, 0, 7, 0, 0, 5, 0},
		{0, 5, 0, 4, 8, 3, 0, 2, 0},
		{6, 0, 3, 0, 1, 0, 5, 0, 0},
		{8, 0, 0, 2, 0, 5, 3, 0, 9},
		{1, 4, 0, 0, 0, 8, 0, 9, 0},
		{2, 8, 0, 9, 4, 0, 0, 0, 5},
		{0, 0, 0, 6, 0, 7, 8, 0, 0}
	} };

	jogoAtual(jogo);
	return 0;
}

bool check(const sudoku& jogo, int valor, int bLinha, int bCol) {

	int iniLinBloc = (bLinha / 3) * 3;
	int iniColBloc = (bCol   / 3) * 3;

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			int riniLinBloc = iniLinBloc + i;
			int riniColBloc = iniColBloc + i;

			if (jogo[riniLinBloc][riniColBloc] == valor) {
				return false;
			}
		}
	}

	for (int i = 0; i < 9; i++) {
			if (jogo[bLinha][i] == valor) {
				return false;
		}
	}
	for (int i = 0; i < 9; i++) {
		if (jogo[i][bCol] == valor) {
			return false;
		}
	}

	return true;
}

bool GiO(const sudoku& jogo) {
	for (const auto& linha : jogo) {
		for (const auto& valor : linha) {
			if (valor == 0 )return false;
		}
	}
	return true;
}

void printJogo(const sudoku& jogo) {
	cout << "-------------------------" << endl;
	for (int i = 0; i < 9; i++) {
		cout << "| ";
		for (int j = 0; j < 9; j++) {
			cout << jogo[i][j] << " ";
			if ((j + 1) % 3 == 0) cout << "| ";
		}
		cout << endl;
		if ((i + 1) % 3 == 0) cout << "-------------------------" << endl;
	}
}

void jogoAtual(sudoku& jogo) {

	printJogo(jogo);
	string pos;
	int linha = 0, col = 0, num1 = 0;

	cout << "Escolha a posicao (linha coluna numero) " << endl;
	getline(cin, pos);
	stringstream ss(pos);
	ss >> linha >> col >> num1;

	if (GiO(jogo) == true) {
		cout<< "Acabou!";
	}

	if (check(jogo, num1, linha, col) == true)
	{
		jogo[linha][col] = num1;
		cout << "Deu certo" << endl;
		jogoAtual(jogo);
	}
	else {
		cout << "Nao pode" << endl;
		jogoAtual(jogo);
	}
	
}



