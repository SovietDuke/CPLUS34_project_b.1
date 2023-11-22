#pragma once
#include "User.h"
#include "IncorrectLength.h"
#include "Noposition.h"

template <typename T> class UserArray
{
public:
	//дефолтный конструктор
	UserArray() = default;

	//коструктор по количеству пользователей в массиве
	UserArray(int length) : _usersCount(length)
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

	//деструктор
	~UserArray()
	{
		delete[] _users;
	}

	//конструктор копирования
	UserArray(const UserArray& UserArray)
	{
		reallocate(UserArray.getLength());

		for (int i = 0; i < _usersCount; ++i)
			_users[i] = UserArray._users[i];
	}

	//функция изменения количества пользователей в массиве
	void reallocate(int newLength)
	{
		erase();

		if (newLength <= 0)
			return;

		_users = new T[newLength];
		_usersCount = newLength;
	}

	//функция очистки массива пользователей
	void erase()
	{
		delete[] _users;
		_users = nullptr;
		_usersCount = 0;
	}

	//оператор присвоения
	T& operator[](int i)
	{
		if (i >= 0 and i <= _usersCount)
			return _users[i];
		else
			throw NoPosition();
	}

	//функция отражения информации по всем пользователям в массве
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

	//функция добавления пользователя в массив
	void add(T user)
	{
		T* newUsers = new T[_usersCount + 1];
		for (int i = 0; i < _usersCount; i++)
		{
			newUsers[i] = _users[i];
		}
		newUsers[_usersCount] = user;
		delete[] _users;
		_users = newUsers;
		++_usersCount;
	}

	//функция удаления пользователя из массива
	void remove(T user)
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

	//функция получения класса пользователя из массива по его id
	User* getUserByID(unsigned long ID)
	{
		for (int i = 0; i < _usersCount; i++)
		{
			if (_users[i]->_id == ID) return _users[i];
			return 0;
		}
	}

	//функция получения класса пользователя из массива по его имени
	User* getUserByName(std::string Name)
	{
		for (int i = 0; i < _usersCount; i++)
		{
			if (_users[i]->_username == Name) return _users[i];
		}
		return 0;
	}

	// геттер количества пользователей в массиве
	int getLength()
	{
		return _usersCount;
	}
private:
	T* _users; // ссылка на массив
	int _usersCount; // счётчик пользователей в массиве
};
