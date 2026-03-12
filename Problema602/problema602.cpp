#include <iostream>
#include <list>
#include <algorithm>
#include <string>
#include <map>
#include <vector>
#include <sstream>

using namespace std;
// double linked list with struct or whatever but using classes
int main()
{
    int nLines;
    cin >> nLines;
    for (int i = 0; i < nLines; i++)
    {
        int objetivo;
        cin >> objetivo;
        int cDia = 0;
        int d1 = 1;
        int d2 = 1;
        int dias = 1;
        while (cDia < objetivo)
        {
            cDia = d1 * 2 + d2;
            d1 = d2;
            d2 = cDia;
            dias++;
        }
        cout << dias << "\n";
    }
    return 0;
}