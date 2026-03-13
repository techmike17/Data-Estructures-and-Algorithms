#include <iostream>
#include <algorithm>
using namespace std;

int main()
{

    long long int max = -1;
    long long int num;
    long long int tam;

    while (cin >> tam)
    {
        for (int i = 0; i < tam; i++)
        {
            cin >> num;
            if (num > max)
                max = num;
        }
        cout << max << "\n";
        max = -1;
    }

    return 0;
}