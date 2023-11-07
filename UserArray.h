#pragma once
#include "User.h"

template <typename T> class UserArray
{
public:
	UserArray() = default;
	UserArray(int length);
	~UserArray();
	UserArray(const UserArray& UserArray);
	void reallocate(int newLength);
	void erase();
	void print();
	T& operator[](int i);
	void add(T user);
	void remove(T user);
	User* getUserByID(unsigned long ID);
	User* getUserByName(std::string Name);
	int getLength();
protected:
	unsigned long _lastID;
	T* _users;
	int _usersCount;
};
