#include <iostream>
#include <list>
#include <algorithm>
#include <string>

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

    ~Node()
    {
        delete next;
    }

    static ::Node *sortedInsert(Node *head, WordInfo wi)
    {
        Node *newNode = new Node(wi);
        // The list is empty
        if (head == nullptr)
            return newNode;
        // The new word is minor than the actual head
        if (wi.word < head->wl.word)
        {
            newNode->next = head;
            head->prev = newNode;
            return newNode;
        }
        // The new word is equal to the head
        if (wi.word == head->wl.word)
        {
            int newLine = wi.wLines.front(); // el número de línea nuevo
            if (head->wl.wLines.back() != newLine)
            {
                head->wl.wLines.emplace_back(newLine);
            }
        }
        //The new word is greater than the head
        else
        {
            // Traverse the list to find correct position
            Node *curr = head;
            while (curr->next != nullptr && curr->next->wl.word < wi.word)
            {
                curr = curr->next;
            }
            if (curr->next != nullptr)
            {
                if (curr->next->wl.word == wi.word)
                {
                    // cout << "word is already in: " + wi.word + "\n";
                    int newLine = wi.wLines.front(); // el número de línea nuevo
                    if (curr->next->wl.wLines.back() != newLine)
                    {
                        curr->next->wl.wLines.emplace_back(newLine);
                    }
                }
                else
                {
                    // cout << "insert in between: " + wi.word + "\n";
                    newNode->next = curr->next;
                    if (curr->next != nullptr)
                    {
                        curr->next->prev = newNode;
                    }
                    curr->next = newNode;
                    newNode->prev = curr;
                }
            }
            else
            { // Insert the new node in the correct position
                // cout << "insert at the end: " << wi.word << "\n";
                newNode->next = curr->next;
                if (curr->next != nullptr)
                {
                    curr->next->prev = newNode;
                }
                curr->next = newNode;
                newNode->prev = curr;
            }
        }
        return head;
    }

    void printList(Node *curr)
    {
        while (curr != nullptr)
        {
            cout << curr->wl.word << " ";
            for (int l : curr->wl.wLines)
                cout << l << " ";
            cout << "\n";
            curr = curr->next;
        }
        cout << "----\n";
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
    int nLine = 1;
    string line;
    getline(cin, line);
    bool firstWord = true;
    Node *head = nullptr;
    getline(cin, line);

    while (line != "0")
    {
        string temp;
        // cout << "linea: " << nLine << endl;

        auto insertWord = [&](const string &w)
        {
            if (w.size() > 2)
            {
                WordInfo tempWI;
                tempWI.wLines.push_front(nLine);
                tempWI.word = w;
                // cout << "palabra: " + w + "\n";
                if (firstWord)
                {
                    head = new Node(tempWI);
                    firstWord = false;
                }
                else
                {
                    head = Node::sortedInsert(head, tempWI);
                }
            }
        };

        for (char c : line)
        {
            if (c != ' ')
            {
                temp += tolower(c);
            }
            else
            {
                insertWord(temp);
                temp = "";
            }
        }
        insertWord(temp); // ✅ última palabra
        nLine++;
        // head->printList(head);

        getline(cin, line);
    }
    head->printList(head);
    return 0;
}