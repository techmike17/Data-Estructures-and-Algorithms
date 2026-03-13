#include <iostream>
#include <list>
#include <algorithm>
#include <string>
#include <map>
#include <vector>
#include <sstream>

using namespace std;

string horaReflejada(string hor, string min)
{
    int minutos[58];
    for (int i = 0; i < 60; i++)
    {
        minutos[i] = i;
    }
    int horas[12];
    for (int i = 1; i <= 12; i++)
    {
        horas[i] = i;
    }
    if (hor == "12" && min == "00" || hor == "06" && min == "00")
    {
        cout << hor << ':' << min;
    }
    int m = stoi(min);
    int h = stoi(hor);
    if (m < 30)
    {

    }
}

int main()
{
    int nLines;
    cin >> nLines;
    for (int i = 0; i < nLines; i++)
    {
        string horas, min;
        char colon;
        cin >> horas >> colon >> min;
        horaReflejada(horas, min);
    }
    return 0;
}