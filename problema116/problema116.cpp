#include <iostream>
#include <vector>
using namespace std;

int main()
{
    const int result[6] = {1, 1, 2, 6, 4, 0}; // fact[i] % 10
    int num;
    while (cin >> num)
    {
        switch (num)
        {
        case 0:
            break;
        case 1:
            cout << "Hola mundo.\n";
            break;
        case 2:
            cout << "Hola mundo.\nHola mundo.\n";
            break;
        case 3:
            cout << "Hola mundo.\nHola mundo.\nHola mundo.\n";
            break;
        case 4:
            cout << "Hola mundo.\nHola mundo.\nHola mundo.\nHola mundo.\n";
            break;
        default:
            cout << "Hola mundo.\nHola mundo.\nHola mundo.\nHola mundo.\nHola mundo.\n";
            break;
        }
    }

    return 0;
}