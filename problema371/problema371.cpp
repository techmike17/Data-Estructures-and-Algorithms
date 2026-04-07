#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

int main()
{
    int nCerillasLados;
    cin >> nCerillasLados;
    while (nCerillasLados)
    {
        int nCerillas = 0;

        for (int i = 1; i <= nCerillasLados; i++)
        {
            nCerillas = nCerillas + 3 * i;
        }
        cout << nCerillas << "\n";
        cin >> nCerillasLados;
    }
    return 0;
}