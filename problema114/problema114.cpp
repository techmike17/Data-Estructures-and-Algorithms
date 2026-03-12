#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int nLines;
    cin >> nLines;
    for (int i = 0; i < nLines; i++)
    {
        int num;
        cin >> num;
        switch (num)
        {
        case 0:
            cout << "1\n";
            break;
        case 1:
            cout << "1\n";
            break;
        case 2:
            cout << "2\n";
            break;
        case 3:
            cout << "6\n";
            break;
        case 4:
            cout << "4\n";
            break;
        default:
            cout << "0\n";
            break;
        }
        
    }

    return 0;
}