#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

int main()
{
    double num;
    double acum = 0;
    double last = 0;

    cin >> num;
    while (num)
    {
        do
        {

            if ((acum - last) < num)
            {
                acum = acum + (num - (acum - last));
            }

            last = num;
            cin >> num;
        } while (num != 0);
        cout << acum << "\n";
        cin >> num;
        acum = 0;
        last = 0;
    }

    return 0;
}