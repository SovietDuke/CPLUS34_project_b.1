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
	user->setID(UserArray<User*>::_lastID);
}
User* UserArray<User*>::getUserByID(unsigned long ID)
{
	for (int i = 0; i < m_length; i++)
	{
		if (m_data[i]->_id == ID)
	}
}
User* UserArray<User*>::getUserByName(std::string Name)
{

}