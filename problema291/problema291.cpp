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
    string line;
    getline(cin, line);
    int nLine = 1;
    map<string, vector<int>> words;
    getline(cin, line);

    while (line != "0")
    {
        stringstream ss(line);
        string word;

        while (ss >> word) // separa por espacios automáticamente
        {
            transform(word.begin(), word.end(), word.begin(), ::tolower);

            if (word.size() > 2)
            {
                if (!words.count(word))
                    words[word] = {nLine};
                else if (words[word].back() < nLine)
                    words[word].push_back(nLine);
            }
        }

        nLine++;
        getline(cin, line);
    }
    for (auto const &x : words)
    {
        cout << x.first;
        for (int i : x.second)
            cout << " " << i;
        cout << "\n";
    }
    cout << "---\n";
    return 0;
}