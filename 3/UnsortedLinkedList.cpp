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

class UnsortedLinkedList
{
public:
    Node *head = NULL;
    Node *tail = NULL;
    int length = 0;

    /**
     * Adds Element on the first index
     * @param d
     */
    void push_front(int d)
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

        length++;
    }

    /**
     * @brief Adds Element at last index
     * @brief Time Complexity @b O(1)
     * @param data
     */
    void push_back(int d)
    {
        Node *newNode = new Node(d);
        Node *temp = tail;
        if (tail == NULL)
        {
            tail = newNode;
            head = newNode;
            length++;
            return;
        }
        temp->next = newNode;
        newNode->prev = temp;
        tail = newNode;

        length++;
    }

    void pop_front()
    {
        if (head->next != NULL)
            head = head->next;
        else
        {
            head = head->next;
            tail = tail->prev;
        }

        length--;
    }

    void pop_back()
    {
        if (tail->prev == NULL)
        {
            tail = NULL;
            head = NULL;
            length--;
            return;
        }

        tail = tail->prev;
        tail->next = NULL;
        length--;
    }
    void print()
    {
        cout << "[";
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data;
            temp = temp->next;
            if (temp != NULL)
            {
                cout << ", ";
            }
        }
        cout << "]";
        cout << endl;
    }
};
int main()
{
    UnsortedLinkedList sll;
    sll.push_back(1);
    sll.push_back(2);
    sll.push_back(3);

    sll.pop_front();
    sll.pop_back();

    sll.print();
    cout << sll.length << endl;
    return 0;
}