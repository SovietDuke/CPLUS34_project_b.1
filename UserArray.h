#pragma once
#include "Array.h"
#include "User.h"

template <typename T = User*> class UserArray : public Array<T>
{
public
	UserArray();
	~UserArray();
	void print();
	void add(User* user);
	User* getUserByID(unsigned long ID);
	User* getUserByName(std::string Name);
protected:
	unsigned long _lastID = 0;
};
