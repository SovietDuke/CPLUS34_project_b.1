#include "UserArray.h"

template<> UserArray<User*>::UserArray()
{

};
template<> UserArray<User*>::~UserArray() {};
template<> void UserArray<User*>::print()
{
	if (m_data)
	{
		for (int i = 0; i < m_length; i++)
		{
			m_data[i]->printUser();
		}
	}
}
void UserArray<User*>::add(User* user)
{
	m_data[m_length] = user;
	user->setID(UserArray::_lastID);
}
template<> unsigned long UserArray<User*>::getID(std::string username)
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