#include <iostream>
#include <list>
#include <algorithm>
#include <string>
#include <map>
#include <vector>
#include <sstream>

using namespace std;
// double linked list with struct or whatever but using classes
int main()
{
    int nLines;
    cin >> nLines;
    while (nLines != 0)
    {
        char aux;
        cin.get(aux);
        string line;
        map<string, vector<int>> words;

        for (int i = 1; i <= nLines; i++)
        {
            getline(cin, line);
            stringstream ss(line);
            string word;

            while (ss >> word) // separa por espacios automáticamente
            {

                if (word.size() > 2)
                {
                    transform(word.begin(), word.end(), word.begin(), ::tolower);

                    if (!words.count(word))
                        words[word] = {i};
                    else if (words[word].back() < i)
                        words[word].push_back(i);
                }
            }
        }

        for (auto const &x : words)
        {
            cout << x.first << ' ';
            for (int i = 0; i < x.second.size(); i++)
            {
                cout << x.second[i];
                if (i < x.second.size() - 1)
                    cout << ' ';
            }
            cout << '\n';
        }
        cout << "----\n";
        cin >> nLines; // ✅ convierte string a int
    }
    return 0;
}