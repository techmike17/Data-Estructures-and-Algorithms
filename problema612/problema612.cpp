#include <iostream>
#include <cmath>

using namespace std;

double euclideanDistance(int radio, int x1, int y1, int x2, int y2)
{
    double first = (double)(x1 - x2);
    double second = (double)(y1 - y2);
    double distance = sqrt(first * first + second * second);
    return distance;
}

int numPuntosCirculos(int radio, int x1, int y1, int x2, int y2)
{
    int res = 0;
    double distance = 0;
    while (radio > 0)
    {
        distance = euclideanDistance(radio, x1, y1, x2, y2);
        if (distance <= radio)
            res++;
        if (radio > 1)
        {
        }
    }
    return res;
}

int main()
{
    int radio, x2, y2, res = 0;
    while (
        cin >> radio >> x2 >> y2)
    {
        res = numPuntosCirculos(radio, x2, y2);
        cout << res << "\n";
        res = 0;
    }
    return 0;
}