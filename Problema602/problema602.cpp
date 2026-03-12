#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int nLines;
    cin >> nLines;
    for (int i = 0; i < nLines; i++)
    {
        double objetivo;
        cin >> objetivo;
        double accDia = 2;
        double dias = 1;
        double d1, d2;
        d1 = 1;
        d2 = 1;

        if (objetivo == 1)

            cout << dias << "\n";

        else if (objetivo == 2)

            cout << dias + 1 << "\n";

        else
        {
            dias = 2;
            do
            {
                int dactual = d2 * 2 + d1;
                accDia += dactual;
                d2 = d1;
                d1 = dactual;
                dias++;

            } while (accDia < objetivo);
            cout << dias << "\n";
        }
    }

    return 0;
}