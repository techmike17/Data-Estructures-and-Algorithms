#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct WordInfo{
    string word;
    vector<int> lines;
};

int main()
{
    string a = "garrapata";
    string b = "garrapatas";
    if(a<b)
    {
        cout << a << " es menor que " << b << endl;
    }
    else
    {
        cout << a << " es mayor que " << b << endl;
    }
}