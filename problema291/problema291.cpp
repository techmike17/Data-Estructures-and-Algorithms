#include <iostream>
#include <list>
#include <algorithm>

using namespace std;
struct WordInfo
{
    string word;
    list<int> wLines;
};

class Node
{
    WordInfo wl;
    Node *prev;
    Node *next;

public:
    Node(WordInfo newWL)
    {
        wl = newWL;
        prev = nullptr;
        next = nullptr;
    }

public:
    Node *sortedInsert(Node *head, WordInfo wi)
    {
        Node *newNode = new Node(wi);
        if (head = nullptr)
            return newNode;

        if (wi.word < head->wl.word)
        {
            newNode->next = head;
            head->prev = newNode;
            return newNode;
        }
        // Traverse the list to find correct position
        Node *curr = head;
        while (curr->next != nullptr && curr->next->wl.word < wi.word)
        {
            curr = curr->next;
        }
        if (curr->wl.word == wi.word)
            curr->wl.wLines.push_back(wi.wLines.front());
        else
        {
            // Insert the new node in the correct position
            newNode->next = curr->next;
            if (curr->next != nullptr)
            {
                curr->next->prev = newNode;
            }
            curr->next = newNode;
            newNode->prev = curr;
        }
        return head;
    }

    void printList(Node *curr)
    {
        while (curr != nullptr)
        {
            cout << curr->wl.word << " " << curr->wl.wLines.front() << "\n";
            curr = curr->next;
        }
    }
};
// double linked list with struct or whatever but using classes
int main()
{
    int nFilas;
    char c;
    /*
    Coger la entrada por caracteres, guardar la palabra con cada espacio si su longitud es mayor a 2.
    Guardar la palabra en una lista de palabras, insercion ordenada, junto con la línea en la que aparece.
    si la palabra ya existe, añadir la línea a la lista de líneas en las que aparece.
    [
    "word1": [line1, line2, line3],
    "word2": [line1, line2]
    ]
    */
    cin >> nFilas;
    int nLine = 0;
    string line;
    getline(cin, line);
    bool firstWord = false;
    Node* head;
    while (line != "0")
    {
        nLine++;
        string temp;

        for (char c : line)
        {
            if (c != ' ')
            {
                c = tolower(c);
                temp += c;
            }
            else if (temp.size() > 2)
            {
                WordInfo tempWI;
                tempWI.wLines.push_front(nLine);
                tempWI.word = temp;
                if (firstWord)
                    head = new Node(tempWI);
                else
                {
                    head = sortedInsert(tempWI);
                }
                cout << "temp is:" << temp << endl;

                temp = "";
            }
            else
                temp = "";
        }

        getline(cin, line);
    }
    return 0;
}