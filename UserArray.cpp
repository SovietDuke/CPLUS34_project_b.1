#include "UserArray.h"

template<> UserArray<User>::UserArray(){}
template<> UserArray<User>::~UserArray(){}
template<> void UserArray<User>::print() const
{
	if (m_data)
	{
		for (int i = 0; i < m_length; i++)
		{
			m_data[i].printUser();
		}
	}
}
template<> void UserArray<User>::insertAtEnd(User User)
{
	this->insertAtEnd(User);
	User._id = ++_lastID;
	_userID.insertAtEnd(_lastID);
}
template<> unsigned long UserArray<User>::getID(std::string username) const
{
	if (m_data)
	{
		for (int i = 0; i < m_length; i++)
		{
			if (m_data[i]._username == username)
				return m_data[i]._id;
		}
	}
	return 0;
}