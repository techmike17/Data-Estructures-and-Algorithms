#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int nFilas;
    string word[nFilas];
    cin >> nFilas;
    /*
    Coger la entrada por caracteres, guardar la palabra con cada espacio si su longitud es mayor a 2. 
    Guardar la palabra en una lista de palabras, insercion ordenada, junto con la línea en la que aparece.
    si la palabra ya existe, añadir la línea a la lista de líneas en las que aparece.
    [
    "word1": [line1, line2, line3],
    "word2": [line1, line2]
    ]
    */
    for (int i = 0; i < nFilas; i++) {
        cin >> word[i];
    }
    cout << "The words are: ";
    for (int i = 0; i < nFilas; i++) {
        cout << word[i] << " ";
    }
    cout << endl;
    return 0;
}