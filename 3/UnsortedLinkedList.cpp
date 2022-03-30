#include <iostream>
#include <stdexcept>
using namespace std;

class Node {
   public:
    int data;
    Node *next = NULL;
    Node *prev = NULL;

    Node(int d) { data = d; }
};

class UnsortedLinkedList {
   public:
    Node *head = NULL;
    Node *tail = NULL;
    int length = 0;

    /**
     * Adds Element on the first index
     * @param d
     */
    void push_front(int d) {
        Node *newNode = new Node(d);
        Node *temp = head;
        if (temp != NULL) {
            temp->prev = newNode;
        } else {
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
    void push_back(int d) {
        Node *newNode = new Node(d);
        Node *temp = tail;
        if (tail == NULL) {
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

    void pop_front() {
        if (head->next != NULL)
            head = head->next;
        else {
            head = head->next;
            tail = tail->prev;
        }

        length--;
    }

    void pop_back() {
        if (tail->prev == NULL) {
            tail = NULL;
            head = NULL;
            length--;
            return;
        }

        tail = tail->prev;
        tail->next = NULL;
        length--;
    }
    void remove(int ele) {
        Node *temp = head;
        while (temp != NULL) {
            if (ele == temp->data) {
                if (temp->prev != NULL) {
                    temp->prev->next = temp->next;
                    if (temp->next != NULL) {
                        temp->next->prev = temp->prev;
                    }
                    length--;
                } else {
                    pop_front();
                }
            }
            temp = temp->next;
        }
    }
    void print(ostream &os) const {
        os << "[";
        Node *temp = head;
        while (temp != NULL) {
            os << temp->data;
            temp = temp->next;
            if (temp != NULL) {
                os << ", ";
            }
        }
        os << "]";
    }

    friend ostream &operator<<(ostream &os, const UnsortedLinkedList &usll) {
        usll.print(os);
        return os;
    }

    int &operator[](int index) {
        if (index >= length) {
            cerr << "Index out of Bounds" << endl;
            exit(0);
        }

        int i = 0;
        Node *temp = head;
        while (i != index && temp != NULL) {
            temp = temp->next;
            i++;
        }

        return temp->data;
    }

    /**
     * @brief  Linear Search on Linked List,
     *
     * @param key
     * @return int
     *  the first index element found on.
     * if element is not found returns @b -1
     */
    int search(int key) {
        int i = 0;
        Node *temp = head;

        while (temp != NULL) {
            if (temp->data == key) {
                return i;
            }
            i++;
            temp = temp->next;
        }

        return -1;
    }
};

int main() {
    UnsortedLinkedList usll;
    cout << usll.length << endl;
    cout << usll << endl;
    cout << usll[1] << endl;
    cout << usll.search(6) << endl;
    return 0;
}
