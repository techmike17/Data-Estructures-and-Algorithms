#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

int main()
{
    double num;
    cin >> num;
    while (num)
    {
        double numCero = 0;
        double mult = 1;
        double aux = num;
        do
        {
            do
            {
                double mod = (int) aux % 10;
                aux /= 10;
                if (mod == 0)
                    numCero++;
                else
                    mult *= mod;

            } while (aux >= 1);
            aux = mult;
            mult = 1;
        } while (aux > 9);
        cout << aux << numCero << "\n";
        cin >> num;
    }
    return 0;
}