#include <iostream>
#include <cmath>

using namespace std;

double euclideanDistance(int radio, int x1, int y1, int x2, int y2)
{
    int first = x1 - x2;
    int second = y1 - y2;
    first *= first;
    second *= second;
    double distance = sqrt(first + second);
    return distance;
}

int numPuntosCirculos(int radio, int x1, int y1, int x2, int y2)
{
    int res = 0;
    if (radio > 0)
    {
        double distance = euclideanDistance(radio, x1, y1, x2, y2);
        res = (distance <= radio) ? 1 : 0;

        if (y2 == y1) // The point is on the x axis
        {
            if (x2 == x1) // the point is the center of the circle so it will be included only in the first circle
            {
                return 1;
            }
            if (x2 > x1)
            {
                res += numPuntosCirculos(radio / 2, x1 + radio, y1, x2, y2);
            }
            else if (x2 < x1)
            {
                res += numPuntosCirculos(radio / 2, x1 - radio, y1, x2, y2);
            }

            else if (x2 > x1 + radio) // out of the actual circle
            {
                res += numPuntosCirculos(radio / 2, x1 + radio, y1, x2, y2);
            }
            else if (x2 < x1 - radio)
            {
                res += numPuntosCirculos(radio / 2, x1 - radio, y1, x2, y2);
            }
        }
        else if (y2 > 0) // the point is in the first or second quadrant
        {
            if (x2 == 0)
            {
            }
            else if (x2 > 0) // first quadrant
            {
            }
            else //
            {
            }
        }
        else // the point is in the third or forth quadrant
        {
            if (x2 == 0)
            {
            }
            else if (x2 > 0)
            {
            }
            else
            {
            }
        }
    }
    return res;
}

int main()
{
    int radio, x2, y2, res = 0;
    while (1)
    {
        cin >> radio >> x2 >> y2;
        res += numPuntosCirculos(radio, 0, 0, x2, y2);
        cout << res << "\n";
        res = 0;
    }
    return 0;
}