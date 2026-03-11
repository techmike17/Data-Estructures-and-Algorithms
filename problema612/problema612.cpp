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
        distance = euclideanDistance(radio, 0, 0, x2, y2);
        if (distance <= radio)
            res++;
        if (radio > 1)
        {
            int nextX = abs(x2 - radio);
            int nextY = abs(y2 - radio);

            if (nextY < nextX)
            {
                // next point is up or down
                if (y2 < 0) // go to down
                {
                    y2 = y2 - radio;
                    y1 = y1 - radio;
                }
                else if (y2 > 0) // go to up
                {
                    y2 = y2 - radio;
                    y1 = y1 + radio;
                }
            }
            else if (nextY > nextX)
            {
                // next point is left or right
                if (x2 < 0) // go to the left
                {
                    x2 = x1 + radio;
                    x1 = x1 - radio;
                }
                else if (x2 > 0) // go to the right
                {
                    x2 = x2 - radio;
                    x1 = x1 + radio;
                }
            }
            else
            {
                // the point is on a diagonal doesnt matter axis Y or X
                if (x2 < 0) // go to the left
                {
                    x2 = x2 + radio;
                    x1 = x1 - radio;
                }
                else if (x2 > 0) // go to the right
                {
                    x2 = x2 - radio;
                    x1 = x1 + radio;
                }
            }
        }
        radio = radio / 2;
    }
    return res;
}

int main()
{
    int radio, x2, y2, res = 0;
    while (
        cin >> radio >> x2 >> y2)
    {
        res = numPuntosCirculos(radio, 0, 0, x2, y2);
        cout << res << "\n";
        res = 0;
    }
    return 0;
}