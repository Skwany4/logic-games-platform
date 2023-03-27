#include <iostream>
#include <fstream>
#include <string>
#include "Tictactoe.h"

void Tictactoe::showboard() {
	std::cout << "\n | " << board[0] << " | " << board[1] << " | " << board[2] << " |\n" << std::endl;
	std::cout << " | " << board[3] << " | " << board[4] << " | " << board[5] << " |\n" << std::endl;
	std::cout << " | " << board[6] << " | " << board[7] << " | " << board[8] << " | " << std::endl;
}
