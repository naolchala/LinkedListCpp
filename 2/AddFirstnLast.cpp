#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next = NULL;
    Node *prev = NULL;

    Node(int d)
    {
        data = d;
    }
};

class LinkedList
{
public:
    Node *head = NULL;
    Node *tail = NULL;

    void addFirst(int d)
    {
        Node *newNode = new Node(d);
        Node *temp = head;
        if (temp != NULL)
        {
            temp->prev = newNode;
        }
        else
        {
            tail = newNode;
        }
        newNode->next = temp;
        head = newNode;
    }

    void addLast(int d)
    {
        Node *newNode = new Node(d);
        Node *temp = tail;
        if (tail == NULL)
        {
            tail = newNode;
            head = newNode;
            return;
        }
        temp->next = newNode;
        newNode->prev = temp;
        tail = newNode;
    }

    void print()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data;
            temp = temp->next;
            if (temp != NULL)
            {
                cout << " <-> ";
            }
        }
        cout << endl;
    }
};

int main()
{
    LinkedList ll;
    ll.addFirst(0);
    ll.addFirst(1);
    ll.addFirst(2);
    ll.addFirst(3);
    ll.addLast(5);

    cout << "Tail: " << ll.tail->data << endl;
    cout << "Head: " << ll.head->data << endl;
    ll.print();
    return 0;
}