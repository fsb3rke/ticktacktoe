#include <iostream>

#define EMPTY 0
#define X 1
#define O 2

#define game_coord(x) x-1

bool isGameOver = false;
int coords[9] = { 0, 0, 0,
				 0, 0, 0,
				 0, 0, 0 };
bool object = true; // ' X ' starts

void init();
void ShowTable();
std::string GetObject(int index);
std::string GetObject(bool object, std::string str);
int GetObject(bool object, int inte);
void Win();
void Add(int object, int coord);
void Game();

int main()
{
	init();
	do
	{
		Game();
	} while (isGameOver != true);
	ShowTable();
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
	if (coords[index] == EMPTY)  return "N";
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

void Game() {
	/*
	true:  ' X '
	false: ' O '
	*/

	
	ShowTable();

	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;

	int coord;
	std::cout << GetObject(object, "") << " , Please enter a coord (1-9) : ";
	std::cin >> coord;
	Add(GetObject(object, 0), coord);
	object = !object;
	Win();
	std::cout << std::endl;
}