#pragma once
#include "User.h"
#include "IncorrectLength.h"
#include "Noposition.h"

template <typename T> class UserArray
{
public:
	UserArray() = default;
	template<typename T> UserArray(int length) : _usersCount(length)
	{
		if (length <= 0)
		{
			throw IncorrectLength();
		}
		else
		{
			_users = new T[length]{};
		}
	};
	~UserArray()
	{
		delete[] _users;
	}
	UserArray(const UserArray& UserArray)
	{
		reallocate(UserArray.getLength());

		for (int i = 0; i < _usersCount; ++i)
			_users[i] = UserArray._users[i];
	}
	void reallocate(int newLength)
	{
		erase();

		if (newLength <= 0)
			return;

		_users = new T[newLength];
		_usersCount = newLength;
	}
	void erase()
	{
		delete[] _users;
		_users = nullptr;
		_usersCount = 0;
	}
	template <typename T> T& operator[](int i)
	{
		if (i >= 0 and i <= _usersCount)
			return _users[i];
		else
			throw NoPosition();
	}
	void print()
	{
		if (_users)
		{
			for (int i = 0; i < _usersCount; i++)
			{
				_users[i]->printUser();
			}
		}
	}
	template<typename T> void add(T* user)
	{
		T* newUsers = new T[_usersCount + 1];
		for (int i = 0; i < _usersCount; i++)
		{
			newUsers[i] = _users[i];
		}
		newUsers[_usersCount + 1] = user;
		delete[] _users;
		_users = newUsers;
		++_usersCount;
	}
	template<typename T> void remove(T user)
	{
		for (int i = 0; i < UserArray<T>::_usersCount; i++)
		{
			if (UserArray<T>::_users[i] == user)
			{
				UserArray<T>::_users[i] = _users[i + 1];
				UserArray<T>::_usersCount--;
			}
		}
	}
	User* getUserByID(unsigned long ID)
	{
		for (int i = 0; i < _usersCount; i++)
		{
			if (_users[i]->_id == ID) return _users[i];
			return 0;
		}
	}
	User* getUserByName(std::string Name)
	{
		for (int i = 0; i < _usersCount; i++)
		{
			if (_users[i]->_username == Name) return _users[i];
			return 0;
		}
	}
	int getLength()
	{
		return _usersCount;
	}
private:
	unsigned long _lastID;
	T* _users;
	int _usersCount;
};
