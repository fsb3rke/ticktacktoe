// Author: fsb3rke

#include <iostream>
#include <conio.h>

#define EMPTY 0
#define X 1
#define O 2

#define game_coord(x) x-1

bool isGameOver = false;
int coords[9] = {
	0, 0, 0,
	0, 0, 0,
	0, 0, 0
};
bool object = true; // ' X ' starts

void init();
void ShowTable();
std::string GetObject(int index);
std::string GetObject(bool object, std::string str);
int GetObject(bool object, int inte);
bool IsWin(int number);
int Win();
void Add(int object, int coord);
void Game();
void EndGame();

int main()
{
	init();
	do
	{
		Game();
	} while (isGameOver != true);
	ShowTable();
	EndGame();
}

void init() {
	system("cls");
}

void Add(int object, int coord) {
	if (coord < 1 || coord > 9) return;
	int element = coords[game_coord(coord)];
	if (element == EMPTY) coords[game_coord(coord)] = object;
}

std::string GetObject(int index) {
	if (coords[index] == EMPTY)  return ".";
	else if (coords[index] == X) return "X";
	else if (coords[index] == O) return "O";
}

std::string GetObject(bool object, std::string str) {
	if (object) return "X";
	else		return "O";
}

int GetObject(bool object, int inte) {
	if (object) return X;
	else		return O;
}

void ShowTable() {
	for (int i = 0; i < sizeof(coords) / sizeof(coords[0]); i++) {
		if (i % 3 == 0) std::cout << std::endl << std::endl << std::endl;
		std::cout << "\t" << GetObject(i);
	}
}

int Win() {
	/*
	0, 0, 0	  <-->	 0, 1, 2
	0, 0, 0	  <-->	 3, 4, 5
	0, 0, 0	  <-->	 6, 7, 8
	*/

	/*
	0, 1, 2		0, 4, 8
	0, 3, 6		2, 4, 6
	6, 7, 8
	2, 5, 8
	1, 4, 7
	3, 4, 5
	*/

	int possibilities[8][3] = {
		{ 0, 1, 2 }, { 0, 3, 6 },
		{ 6, 7, 8 }, { 2, 5, 8 },
		{ 1, 4, 7 }, { 3, 4, 5 },
		{ 0, 4, 8 }, { 2, 4, 6 }
	};

	int degree;
	for (int i = 0; i < sizeof(possibilities) / sizeof(possibilities[0]); i++) {
		degree = 0;
		for (int j = 0; j < sizeof(possibilities[i]) / sizeof(possibilities[i][0]); j++) {
			int element = possibilities[i][j];
			bool isEmpty = coords[element] == EMPTY;
			if (isEmpty == false && coords[element] == X) degree++;
			else if (isEmpty == false && coords[element] == O) degree--;
		}
		if (degree == 3) return 1;
		else if (degree == -3) return -1;
	}

	return 0;
}

bool IsWin(int number) {
	if (number == 1) object = true;
	else if (number == -1) object = false;
	if (number == 1 || number == -1) return true;
	return false;
}

void EndGame() {
	std::string m_object = GetObject(!object, "");
	for (int i = 0; i < 2; i++) std::cout << std::endl;
	std::cout << m_object << " : " << "Won." << std::endl;
	_getch();
}

void Game() {
	/*
	true:  ' X '
	false: ' O '
	*/

	
	ShowTable();

	for (int i = 0; i < 3; i++) std::cout << std::endl;

	int coord;
	std::cout << GetObject(object, "") << " , Please enter a coord (1-9) : ";
	std::cin >> coord;
	Add(GetObject(object, 0), coord);
	isGameOver = IsWin(Win());
	object = !object;
	std::cout << std::endl;
}
