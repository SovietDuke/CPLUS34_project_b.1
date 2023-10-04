#include <iostream>
#include "Array.cpp"
using namespace std;

int main()
{
    setlocale(LC_ALL, "");

    try
    {
        Array<int> array(10);

        for (int i = 0; i < array.getLength(); ++i)
            array[i] = i + 1;

        array.resize(8);

        array.insertBefore(20, 5);

        array.remove(3);

        array.insertAtEnd(30);

        array.insertAtBeginning(40);

        {
            Array<int> b = array;
            b = array;
            b = b;
            array = array;
        }

        for (int i = 0; i < array.getLength(); ++i)
            cout << array[i] << ' ';

        cout << endl;
    }
    catch (const char* exception)
    {
        cout << exception << endl;
    }

    return 0;
}