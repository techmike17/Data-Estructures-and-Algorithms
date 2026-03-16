#include <iostream>
#include <list>
#include <algorithm>
#include <string>
#include <map>
#include <vector>
#include <sstream>

using namespace std;

int main()
{
    int nLines;
    cin >> nLines;
    while (nLines != 0)
    {

        vector<int> dll;

        // Insert elements at the end
        int num;
        for (int i = 0; i < nLines; i++)
        {
            cin >> num;
            dll.push_back(num);
        }

        sort(dll.begin(), dll.end());

        int med = nLines / 2;
        if (nLines % 2)
            cout << dll[med] * 2 << "\n";
        else
            cout << dll[med - 1] + dll[med] << "\n";

        cin >> nLines;
    }
    return 0;
}