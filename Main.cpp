#include <iostream>
#include <string>
#include "UserArray.h"
#include "Chat.h"
using namespace std;

int main()
{
	setlocale(LC_ALL, "");
	Chat ICQ("ICQ");
	User Egor("Egor", "test@gmail.ru", "123");
	User Andrew("Andrei", "test1@gmail.ru", "123");
	ICQ.addUser(&Egor);
	ICQ.addUser(&Andrew);

	return 0;
}