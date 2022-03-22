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

    void print(ostream &os) const
    {
        os << "[";
        Node<T> *temp = head;
        while (temp != NULL)
        {
            os << temp->data;
            if (temp->next != NULL)
            {
                os << ", ";
            }
            temp = temp->next;
        }
        os << "]";
    }

    friend ostream &operator<<(ostream &os, const LinkedList<T> &c)
    {
        c.print(os);
        return os;
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

    T &operator[](int index)
    {
        if (index >= length)
        {
            cerr << "Index out of Bounds" << endl;
            exit(0);
        }

        int i = 0;
        Node<T> *temp = head;

        while (temp != NULL)
        {
            if (i == index)
            {
                break;
            };
            i++;
            temp = temp->next;
        }

        return temp->data;
    }
};

int main()
{
    LinkedList<int> ll;
    LinkedList<int> al;
    LinkedList<LinkedList<int>> mll;

    ll.push_back(1);
    ll.push_back(2);
    ll.push_back(3);

    mll.push_back(ll);
    mll.push_back(ll);

    cout << ll << endl;
    cout << mll << endl;
    cout << mll[0][1] << endl;

    return 0;
}