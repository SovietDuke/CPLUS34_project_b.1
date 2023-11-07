#pragma once
#include "UserArray.h"
#include <iostream>

#define MAX_CHATNAME_SIZE 20
#define MAX_MESSAGE_SIZE 50

class Chat
{
public:
	Chat(std::string chatName);
	void setChatName(std::string newName);
	void menu();
	User* authorization();
	void registration();
	void addUser(User* newUser);
	void deleteUser(User* user);
	void showUsers();
	void sendMessage(User* currentUser);
	void sendMessageToU(User* currentUser);
private:
	std::string _chatName;
	UserArray<User*> _userArray;
};
