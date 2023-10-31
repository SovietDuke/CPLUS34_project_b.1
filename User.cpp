#include "User.h"

User::User(){}
User::User(std::string username)
{
	_username = username;
}
User::User(std::string username, std::string email)
{
	_username = username;
	_email = email;
}
User::User(std::string username, std::string email, std::string password)
{
	_username = username;
	_email = email;
	_password = password;
}
User::~User() {}
void User::setID(unsigned long newID)
{
	_id = newID;
}
void User::setUserName(std::string newName)
{
	_username = newName;
}
void User::setEmail(std::string newEmail)
{
	_email = newEmail;
}
void User::setPassword(std::string newPassword)
{
	_password = newPassword;
}
void User::printUser()
{
	std::cout << "User ID: " << _id << std::endl;
	std::cout << "User name: " << _username << std::endl;
	std::cout << "User email: " << _email << std::endl;
}
unsigned long User::getID() const
{
	return _id;
}
std::string User::getUserName() const
{
	return _username;
}
std::string User::getEmail() const
{
	return _email;
}
std::string User::getPassword() const
{
	return _password;
}