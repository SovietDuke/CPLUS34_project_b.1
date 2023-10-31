#pragma once
#include "Array.h"

class User
{
public:
	User();
	User(std::string username);
	User(std::string username, std::string email);
	User(std::string username, std::string email, std::string password);
	~User();
	void setID(unsigned long newID);
	void setUserName(std::string newName);
	void setEmail(std::string newEmail);
	void setPassword(std::string newPassword);
	void printUser();
	unsigned long getID() const;
	std::string getUserName() const;
	std::string getEmail() const;
	std::string getPassword() const;
	friend User* UserArray<User*>::getUserByID(unsigned long ID);
protected:
	std::string _username; // ограничение - 30 знаков
	unsigned long _id = 0;
	std::string _email; // ограничение - 20 знаков
	std::string _password; // ограничение - 20 знаков
};
