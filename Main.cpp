#include <iostream>
#include <string>
#include "UserArray.h"
using namespace std;

int main()
{
	UserArray<User> UserData;
	User Egor, Sasha;
	Egor.setUserName("Egor");
	Egor.setEmail("kozlovegoryur@gmail.com");
	Sasha.setUserName("Baby");
	UserData.insertAtEnd(Egor);
	UserData.insertAtEnd(Sasha);
	UserData.print();

	return 0;
}