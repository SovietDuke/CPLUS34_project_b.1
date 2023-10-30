#pragma once
#include "Array.h"
#include "User.h"

template <typename T = User*> class UserArray : public Array<User*>
{
public
	UserArray();
	~UserArray();
	void print();
	void add(User* user);
	User::User* getUserByID(unsigned long ID);
	User::User* getUserByName (std::string Name)
protected:
	unsigned long _lastID = 0;
};
