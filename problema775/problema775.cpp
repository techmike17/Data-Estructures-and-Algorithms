#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

int main()
{
    int num;
    int acum = 0;
    int last;

    cin >> num;
    while (num)
    {
        do
        {
            if (acum < num)
            {
                acum += num;
            }
            else
            {
                if (last <= num)
                {
                    if ((acum - last) < num)
                    {
                        acum = acum + (num - (acum - last));
                    }
                }
            }
            last = num;
            cin >> num;
        } while (num != 0);
        cout << acum << "\n";
        cin >> num;
        acum = 0;
    }

    return 0;
}