#include "Chat.h"
#include "ExcLimitUsername.h"
#include "ExcLimitPassword.h"
#include "ExcLimitEmail.h"

Chat::Chat(std::string chatName)
{
	_chatName = chatName;
}
void Chat::setChatName(std::string newName)
{
	_chatName = newName;
}
void Chat::menu()
{
	std::cout << "================== " << _chatName << " ==================" << std::endl << std::endl;
	std::cout << "����������, ������������� ��� ����������� ��� �������� ����� ��� ���������� ���������." << std::endl;
	short command = 0;
	User* currentUser = Chat::authorization();
	if (currentUser)
	{
		std::string input;
		std::cout << "�����:" << std::endl;
		std::cout << "1 - �������� ����." << std::endl;
		std::cout << "2 - ������ ��� � ������ �������������." << std::endl;
		std::cout << "3 - ���������� ������ �������� �������������." << std::endl;
		std::cout << "��� ���������� �������� �������� �����." << std::endl;
		while (command != 3)
		{
			std::cin >> input;
			if (input == "1") command = 0;
			else if (input == "2") command = 1;
			else if (input == "3") command = 2;
			else if (input == "�����" or input == "�����" or input == "�����") command = 3;
			else std::cout << std::endl << "������� ����� �� ������!" << std::endl;
			switch (command)
			{
			case 0:
			{
				Chat::sendMessage(currentUser);
			}
			case 1:
			{
				Chat::sendMessageToU(currentUser);
			}
			case 2:
				Chat::showUsers();
			}
		}
	}
	std::cout << "����� �� ����." << std::endl;
}
User* Chat::authorization()
{
	User* temp;
	std::string input;
	while (input != "�����")
	{
		std::cout << "���:" << std::endl;
		std::cout << "���:" << std::endl;
		std::cin >> input;
		if (input.size() > MAX_USERNAME) throw ExcLimitUsername();
		temp = _userArray.getUserByName(input);
		if (temp)
		{
			std::cout << "������� ������:" << std::endl;
			std::cin >> input;
			if (input.size() > MAX_PASSWORD) throw ExcLimitPassword();
			for (int i = 0; i < 3; i++)
			{
				if (temp->_password == input) return temp;
				std::cout << "������ ��������! ������� ��������: " << 2 - i << std::endl;
			}
			return 0;
		}
		std::cout << std::endl << "������ ������������ �� ����������!" << std::endl;
		std::cout << std::endl << "������ ������������������?" << std::endl;
		std::cout << "������� 1 ��� ����������� ��� ����� ������ ������� ��� ������." << std::endl;
		std::cin >> input;
		if (input == "1") Chat::registration();
		else return 0;
	}
	return 0;
}
void Chat::registration()
{
	std::string name, email, password;
	std::cout << "������� ���: " << std::endl;
	User* temp = nullptr;
	do
	{
		std::cin >> name;
		if (name.size() > MAX_PASSWORD) throw ExcLimitPassword();
		User* temp = _userArray.getUserByName(name);
	} while (temp != nullptr);
	std::cout << "������� ����������� �����: " << std::endl;
	std::cin >> email;
	if (name.size() > MAX_EMAIL) throw ExcLimitEmail();
	std::cout << "���������� ������: " << std::endl;
	std::cin >> password;
	if (password.size() > MAX_PASSWORD) throw ExcLimitPassword();
	User* newUser = new User(name, email, password);
	_userArray.add(newUser);
}
void Chat::addUser(User* newUser)
{
	for (int i = 0; i < Chat::_userArray.getLength(); i++)
	{
		if (Chat::_userArray[i] == newUser) return;
	}
	_userArray.add(newUser);
}
void Chat::deleteUser(User* user)
{
	_userArray.remove(user);
}
void Chat::showUsers()
{
	std::cout << "������� ������������: " << std::endl;;
	for (int i = 0; i < _userArray.getLength(); i++)
	{
		std::cout << Chat::_userArray[i]->_username << std::endl;
	}
}
void Chat::sendMessage(User* currentUser)
{
	std::string message;
	std::cin >> message;
	std::cout << std::endl;
	for (int i = 0; i < Chat::_userArray.getLength(); i++)
	{
		if (Chat::_userArray[i] != currentUser) Chat::_userArray[i]->showMessage(message);
	}
}
void Chat::sendMessageToU(User* currentUser)
{
	std::cout << "������� ��� ������������: " << std::endl;
	std::string secondUserName;
	User* secondUser = Chat::_userArray.getUserByName(secondUserName);
	if (secondUser)
	{
		std::string message;
		std::cin >> message;
		secondUser->showMessage(message);
	}
	else std::cout << "����� ������������ ����������� � ����." << std::endl;
}