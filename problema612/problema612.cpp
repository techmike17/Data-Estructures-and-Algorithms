#include <iostream>
#include <cmath>

using namespace std;

double euclideanDistance(int x1, int y1, int x2, int y2)
{
    double first = (double)(x1 - x2);
    double second = (double)(y1 - y2);
    double distance = sqrt(first * first + second * second);
    return distance;
}

int numPuntosCirculos(int radio, int x2, int y2)
{
    int x1 = 0;
    int y1 = 0;
    int res = 0;
    double distance = 0;
    while (true)
    {
        distance = euclideanDistance(x1, y1, x2, y2);
        if (distance <= radio)
            res++;
        // Δy = y2 - y1  (punto - centro)
        // Δx = x2 - x1  (punto - centro)
        if ((y2 - y1 == x2 - x1) || (y2 - y1 == -x2 + x1)) // el punto cae en una diagonal por lo que se detiene la búsqueda
        {
            break;
        }
        if ((y2 - y1 > x2 - x1) && (y2 - y1 > -x2 + x1)) // Comparamos con las diagonales, por lo que si está por encima de las dos diagonales de pendiente +-1 hay que ir hacia arriba
        {
            y1 += radio;
        }
        else if ((y2 - y1 < x2 - x1) && (y2 - y1 < -x2 + x1)) // si está por debajo de ambas diagonales hay que ir hacia abajo
        {
            y1 -= radio;
        }
        else if (((y2 - y1 > x2 - x1) && (y2 - y1 < -x2 + x1))) // si está por encima de pendien +1 pero por debajo de pendiente -1 izquierda
        {
            x1 -= radio;
        }
        else // por encima de pendiente -1 pero por debajo de pendiente +1
        {
            x1 += radio;
        }

        radio /= 2;
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