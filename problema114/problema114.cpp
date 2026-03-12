#include <iostream>
#include <vector>
using namespace std;

int main()
{
    const int result[6] = {1, 1, 2, 6, 4, 0}; // fact[i] % 10
    int nLines;
    cin >> nLines;
    for (int i = 0; i < nLines; i++)
    {
        int num;
        cin >> num;
        if (num > 5)
            cout << "0\n";
        else
            cout << result[num] << "\n";
    }

    return 0;
}