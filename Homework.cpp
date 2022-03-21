#include <iostream>
using namespace std;

template <typename T>
struct Node
{
    T data;
    Node<T> *next = NULL;
};

template <typename T>
class LinkedList
{
public:
    Node<T> *head = NULL;
    Node<T> *tail = NULL;
    int length = 0;

    void print()
    {
        cout << "[";
        Node<T> *temp = head;
        while (temp != NULL)
        {
            if (is_same<T, LinkedList<int>>::value)
            {
                temp->data.print();
            }
            else
            {
                cout << temp->data;
                if (temp->next != NULL)
                {
                    cout << ", ";
                }
            }
            temp = temp->next;
        }
        cout << "]";
    }

    void push_back(T data)
    {
        Node<T> *NewNode = new Node<T>();
        NewNode->data = data;
        Node<T> *temp = head;

        if (temp == NULL)
        {
            head = NewNode;
            tail = NewNode;
            length++;
            return;
        }

        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = NewNode;
        tail = NewNode;
        length++;
    }
};

int main()
{
    LinkedList<int> ll;
    LinkedList<LinkedList<int>> mll;
    ll.push_back(1);
    ll.push_back(2);
    ll.push_back(3);

    ll.print();
    mll.push_back(ll);
    mll.print();
    return 0;
}