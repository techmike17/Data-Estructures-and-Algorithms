#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;
// double linked list with struct or whatever but using classes
vector<string> split(string str, char delimiter)
{
    vector<string> internal;
    stringstream ss(str); // Turn the string into a stream.
    string tok;

    while (getline(ss, tok, delimiter))
    {
        internal.push_back(tok);
    }

    return internal;
}
int main()
{
    string palabras;
    while (getline(cin, palabras))
    {
        vector<string> splitted = split(palabras, ' ');
        bool chain = true;
        string firsts, lasts = "";

        for (string word : splitted)
        {
            firsts = word[0];
            firsts += word[1];
            if (lasts != "" && lasts != firsts)
            {
                chain = false;
                break;
            }
            lasts = word[word.length() - 2];
            lasts += word[word.length() - 1];
        }

        if (chain)
            cout << "SI\n";
        else
            cout << "NO\n";
    }
    return 0;
}