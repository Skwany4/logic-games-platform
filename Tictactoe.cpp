#include <iostream>
#include <fstream>
#include <string>
#include "Tictactoe.h"

void Tictactoe::showboard() {
	std::cout << "\n | " << board[0] << " | " << board[1] << " | " << board[2] << " |\n" << std::endl;
	std::cout << " | " << board[3] << " | " << board[4] << " | " << board[5] << " |\n" << std::endl;
	std::cout << " | " << board[6] << " | " << board[7] << " | " << board[8] << " | " << std::endl;
}
bool Tictactoe::move(int position, char player) {
	if (board[position - 1] == '-') {
		board[position - 1] = player;
		showboard();
		return true;
	}
	else if (board[position - 1] == 'O' || board[position - 1] == 'X') {
		std::cout << "Invalid move, make it again!\n";
		return false;
	}
}
bool Tictactoe::CheckResult() {
	if ((board[0] == 'X' && board[1] == 'X' && board[2] == 'X') ||
		(board[3] == 'X' && board[4] == 'X' && board[5] == 'X') ||
		(board[6] == 'X' && board[7] == 'X' && board[8] == 'X') ||
		(board[0] == 'X' && board[3] == 'X' && board[6] == 'X') ||
		(board[1] == 'X' && board[4] == 'X' && board[7] == 'X') ||
		(board[2] == 'X' && board[5] == 'X' && board[8] == 'X') ||
		(board[0] == 'X' && board[4] == 'X' && board[8] == 'X') ||
		(board[2] == 'X' && board[4] == 'X' && board[6] == 'X')) {
		std::cout << "Player X win!!";
		return true;
	}
	else if
		((board[0] == 'O' && board[1] == 'O' && board[2] == 'O') ||
			(board[3] == 'O' && board[4] == 'O' && board[5] == 'O') ||
			(board[6] == 'O' && board[7] == 'O' && board[8] == 'O') ||
			(board[0] == 'X' && board[3] == 'X' && board[6] == 'X') ||
			(board[1] == 'O' && board[4] == 'O' && board[7] == 'O') ||
			(board[2] == 'O' && board[5] == 'O' && board[8] == 'O') ||
			(board[0] == 'O' && board[4] == 'O' && board[8] == 'O') ||
			(board[2] == 'O' && board[4] == 'O' && board[6] == 'O'))
	{
		std::cout << "Player O win!!";
		return true;
	}
	else if(board[0] != '-' && board[1] != '-' && board[2] != '-' &&
			board[3] != '-' && board[4] != '-' && board[5] != '-' &&
			board[6] != '-' && board[7] != '-' && board[8] != '-') 
	{
		std::cout << "Draw!!";
		return true;
	}
	else
		return false;

}
void Tictactoe::game() {
	showboard();
	char player = 'X';
	int position;
	while (!CheckResult()) {
		std::cin >> position;
		while (position < 1 || position > 9 || std::cin.fail()) {
			std::cout << "Invalid position, enter position between 1 and 9"<<std::endl;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cin >> position;
		}
		if(move(position, player)==true){
		if (player == 'X') {
			player = 'O';
		}
		else if (player == 'O') {
			player = 'X';

		}
		//else if (move(position, player) == false) {
		//	move(position, player);
		//}
	}
	}
}
// TODO
// SPRAWDZIÆ CZY U¯YTKOWNIK PODA£ INTA A NIE NP. FLOATA, POSZUKAÆ B£ÊDÓW