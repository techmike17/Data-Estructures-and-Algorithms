#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

void horaReflejada(int hor, int min)
{
    int hReflex = 0;
    switch (hor)
    {
    case 1:
        hReflex = 10;
        break;
    case 2:
        hReflex = 9;
        break;
    case 3:
        hReflex = 8;
        break;
    case 4:
        hReflex = 7;
        break;
    case 5:
        hReflex = 6;
        break;
    case 6:
        hReflex = 5;
        break;
    case 7:
        hReflex = 4;
        break;
    case 8:
        hReflex = 3;
        break;
    case 9:
        hReflex = 2;
        break;
    case 10:
        hReflex = 1;
        break;
    case 11:
        hReflex = 12;
        break;
    case 12:
        hReflex = 11;
        break;
    }
    if (min == 0)
        hReflex++;

    if (hReflex == 13)
        hReflex = 1;
    int mReflex = 60 - min;
    cout << std::setw(2) << std::setfill('0') << hReflex << ':' << std::setw(2) << std::setfill('0') << mReflex % 60 << '\n';
}

int main()
{
    int nLines;
    cin >> nLines;
    for (int i = 0; i < nLines; i++)
    {
        int horas, min;
        char colon;
        cin >> horas >> colon >> min;
        horaReflejada(horas, min);
    }
    return 0;
}