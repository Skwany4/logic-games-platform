#include <iostream>
#include <fstream>
#include <string>
#include "Tictactoe.h"

bool login();
bool registration();

int main() {
	int menu_choice,game_choice;
	bool is_logged = false;
	
	std::cout << "~~~~~ MENU ~~~~~\n";
	std::cout << "Choose your action:\n1.Login\n2.Register\n3.EXIT" << std::endl;
	std::cin >> menu_choice;
	system("cls");
	if (menu_choice == 1) {
		is_logged = login();
	}
	else if (menu_choice == 2) {
		while(!registration()) {};
		std::cout << "Good job, now you can login to your new account" << std::endl;
		is_logged = login();
	}
	else if (menu_choice == 3) {
		std::cout << "Goodbye, have a nice day!";
		return 0;
	}
	if(is_logged==true){
		std::cout << "Choose your game:\n1.Tic Tac Toe";
		std::cin >> game_choice;
		if (game_choice == 1) {
			Tictactoe game;
			game.showboard();
		}
	}
	else {
		std::cout << "Error, run application once again";
	}
	

}


bool login() {
	std::string username, password, u, p;
	std::fstream users;
	users.open("Users.txt", std::ios::in);
	int result = 0;
	std::cout << "Enter your username: ";
	std::cin >> username;
	std::cout << "Enter your password: ";
	std::cin >> password;

	while (users >> u >> p) {
		if (username == u && password == p) {
			//std::cout << "Login successful, hello " + username + "!";
			result = 1;
		}
	}
	users.close();
	if (result == 1) {
		std::cout << "Login successful, hello " + username + "!\n";
		return true;
	}
	else {
		std::cout << "Login failed, try again\n";
		return false;
	}
}


bool registration() {
	std::string username, password;
	std::fstream users;

	std::cout << "Enter new username:";
	std::cin >> username;
	std::cout << "Enter your password: ";
	std::cin >> password;

	users.open("Users.txt", std::ios::in | std::ios::out | std::ios::app);
	users << std::endl << username << " " << password;
	users.close();
	// std::cout << "Registration successful, welcome " + username + "!" << std::endl;
	system("cls");

	return true;
};
