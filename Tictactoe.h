#pragma once
#include <iostream>
#include <fstream>
#include <string>

class Tictactoe {
public:
	char board[9] = {'-','-','-','-','-','-','-','-','-'};
	void showboard();
	void game();
	bool move(int move, char player);
	bool CheckResult();
};
