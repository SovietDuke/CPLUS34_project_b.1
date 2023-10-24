#pragma once
#include "Array.h"
#include "User.h"

template <typename T = User> class UserArray : public Array<T>
{
public:
	UserArray();
	~UserArray();
	void print() const;
	void insertAtEnd(User User) override;
	unsigned long getID(std::string username) const;
private:
	Array<unsigned long> _userID{};
	unsigned long _lastID = 0;
};
