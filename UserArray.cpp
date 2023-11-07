#include "UserArray.h"
#include "IncorrectLength.h"
#include "Noposition.h"

template<typename T> UserArray<T>::UserArray(int length) : _usersCount(length)
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
template<typename T> UserArray<T>::~UserArray()
{
	delete[] _users;
}
template <typename T> UserArray<T>::UserArray(const UserArray& UserArray)
{
	UserArray::reallocate(UserArray.getLength());

	for (int i = 0; i < _usersCount; ++i)
		_users[i] = UserArray._users[i];
}
template <typename T> void UserArray<T>::reallocate(int newLength)
{
	UserArray<T>::erase();

	if (newLength <= 0)
		return;

	_users = new T[newLength];
	_usersCount = newLength;
}
template <typename T> void UserArray<T>::erase()
{
	delete[] _users;
	_users = nullptr;
	_usersCount = 0;
}
template <typename T> T& UserArray<T>::operator[](int i)
{
	if (i >= 0 and i <= _usersCount)
		return _users[i];
	else
		throw NoPosition();
}
template<typename T> void UserArray<T>::print()
{
	if (_users)
	{
		for (int i = 0; i < _usersCount; i++)
		{
			_users[i]->printUser();
		}
	}
}
template<typename T> void UserArray<T>::add(T user)
{
	T* newUsers = new T[UserArray<T>::_usersCount + 1];
	for (int i = 0; i < UserArray<T>::_usersCount; i++)
	{
		newUsers[i] = UserArray<T>::_users[i];
	}
	newUsers[UserArray<T>::_usersCount + 1] = user;
	delete[] _users;
	_users = newUsers;
	++_usersCount;
}
template<typename T> void UserArray<T>::remove(T user)
{
	for (int i = 0; i < _usersCount; i++)
	{
		if (_users[i] == user)
		{
			_users[i] = _users[i + 1];
			_usersCount--;
		}
	}
}
template<typename T> User* UserArray<T>::getUserByID(unsigned long ID)
{
	for (int i = 0; i < _usersCount; i++)
	{
		if (_users[i]->_id == ID) return _users[i];
		return 0;
	}
}
template<typename T> User* UserArray<T>::getUserByName(std::string Name)
{
	for (int i = 0; i < _usersCount; i++)
	{
		if (_users[i]->_username == Name) return _users[i];
		return 0;
	}
}
template <typename T> int UserArray<T>::getLength()
{
	return UserArray<T>::_usersCount;
}