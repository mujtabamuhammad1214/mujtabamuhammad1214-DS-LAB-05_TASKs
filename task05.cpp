#include <iostream>
using namespace std;

class Node
{
public:
    char symbol;
    Node *next;

    Node(char c)
    {
        symbol = c;
        next = NULL;
    }
};

class SymbolStack
{
    Node *top;

public:
    SymbolStack()
    {
        top = NULL;
    }

    void push(char c)
    {
        Node *newNode = new Node(c);

        newNode->next = top;
        top = newNode;
    }

    char pop()
    {
        if (top == NULL)
            return '\0';

        char c = top->symbol;

        Node *temp = top;
        top = top->next;

        delete temp;

        return c;
    }

    bool empty()
    {
        return top == NULL;
    }
};

int main()
{
    int n;

    cout << "Enter number of terms: ";
    cin >> n;

    if (n <= 0)
    {
        cout << "Invalid number of terms." << endl;
        return 0;
    }

    int *series = new int[n];

    for (int i = 0; i < n; i++)
    {
        series[i] = 3 * i + 1;
    }

    cout << "\nSeries: ";

    for (int i = 0; i < n; i++)
    {
        cout << series[i];

        if (i != n - 1)
            cout << " + ";
    }

    cout << endl;

    cout << "Postfix: ";

    for (int i = 0; i < n; i++)
    {
        cout << series[i];

        if (i != n - 1)
            cout << " + ";
    }

    cout << endl;

    SymbolStack operators;

    for (int i = 0; i < n - 1; i++)
        operators.push('+');

    cout << "Prefix: ";

    while (!operators.empty())
        cout << operators.pop() << " ";

    for (int i = 0; i < n; i++)
    {
        cout << series[i];

        if (i != n - 1)
            cout << " ";
    }

    cout << endl;

    delete[] series;

    return 0;
}