/**
 *
 */
#include <iostream>
using namespace std;

class Node {
   public:
    int data;
    Node *next = NULL;

    Node(int d) { data = d; }
};

class SinglyLinkedList {
   public:
    Node *head = NULL;
    int length = 0;

    void print();

    void addAtFirst(int data);
    void addAtIndex(int data, int index);
    void addAtLast(int data);

    void removeFirst();
    void removeAtIndex(int index);
    void removeLast();
};

void SinglyLinkedList::print() {
    Node *temp = head;
    while (temp != NULL) {
        cout << temp->data;
        temp = temp->next;
        if (temp != NULL) {
            cout << " -> ";
        }
    }

    cout << endl;
}

void SinglyLinkedList::addAtFirst(int data) {
    Node *newNode = new Node(data);
    Node *temp = head;
    newNode->next = temp;
    head = newNode;
    length++;
};

void SinglyLinkedList::addAtIndex(int data, int index) {
    if (index == 0) {
        addAtFirst(data);
        return;
    } else if (index > length) {
        cerr << "Index Out of Bounds" << endl;
        exit(-1);
    }

    int i = 0;
    Node *temp = head;

    while (temp != NULL && i < index - 1) {
        temp = temp->next;
        i++;
    }

    Node *newNode = new Node(data);
    Node *next = temp->next;
    newNode->next = next;
    temp->next = newNode;
    length++;
};

void SinglyLinkedList::addAtLast(int data) {
    Node *newNode = new Node(data);
    Node *temp = head;

    while (temp->next != NULL) temp = temp->next;

    temp->next = newNode;
    length++;
};

void SinglyLinkedList::removeFirst() {
    head = head->next;
    length--;
}

void SinglyLinkedList::removeAtIndex(int index) {
    if (index == 0)
        removeFirst();
    else if (index > length - 1) {
        cerr << "Index Out of Bounds" << endl;
        exit(-1);
    } else {
        int i = 0;
        Node *temp = head;
        while (temp != NULL && i < index - 1) {
            temp = temp->next;
            i++;
        }
        temp->next = temp->next->next;
        length--;
    }
}

void SinglyLinkedList::removeLast() {
    Node *temp = head;
    while (temp->next->next != NULL) temp = temp->next;
    temp->next = NULL;
    length--;
}

int mainMenu() {
    int menu;
    cout << "1. View List Items" << endl
         << "2. Add Item" << endl
         << "3. Remove Item" << endl
         << "0. Exit" << endl;
    cout << "Enter Menu No.: ";
    cin >> menu;

    if (menu == 1) {
        return menu;
    } else if (menu == 2) {
        cout << "======== ADD ITEM ========" << endl;
        cout << "1. Front " << endl
             << "2. End" << endl
             << "3. At Given Index" << endl;
        cout << "Select Position: ";
        cin >> menu;

        return menu + 3;
    } else if (menu == 3) {
        cout << "======== REMOVE ITEM ========" << endl;
        cout << "1. Front " << endl
             << "2. End" << endl
             << "3. At Given Index" << endl;
        cout << "Select Position: ";
        cin >> menu;

        return menu + 6;
    } else {
        return menu;
    }
}

int main() {
    SinglyLinkedList sll;

    cout << "========================================" << endl
         << "          $ingly Linked List" << endl
         << "========================================" << endl;

    int menu;
    do {
        menu = mainMenu();
        if (menu == 1) {
            cout << endl
                 << "Elements in List" << endl
                 << "----------------" << endl;
            sll.print();
        } else if (menu == 4) {
            cout << endl
                 << "Add Front Element" << endl
                 << "----------------" << endl;
            int no;
            cout << "Enter Num: ";
            cin >> no;

            sll.addAtFirst(no);
        } else if (menu == 5) {
            cout << endl
                 << "Add Last Element" << endl
                 << "----------------" << endl;
            int no;
            cout << "Enter Num: ";
            cin >> no;
            sll.addAtLast(no);
        } else if (menu == 6) {
            cout << endl
                 << "Add Element at Index" << endl
                 << "--------------------" << endl;
            int no, index;
            cout << "Enter Num: ";
            cin >> no;
            do {
                cout << "Enter Index: ";
                cin >> index;

                if (index >= sll.length)
                    cout << "Error: Index out of bounds" << endl;
            } while (index > sll.length);

            sll.addAtIndex(no, index);
        } else if (menu == 7) {
            sll.removeFirst();
            cout << "First Element Removed" << endl;
        } else if (menu == 8) {
            sll.removeLast();
            cout << "Last Element Removed" << endl;
        } else if (menu == 9) {
            cout << endl
                 << "Remove Element at Index" << endl
                 << "----------------------" << endl;
            int index;
            do {
                cout << "Enter Index: ";
                cin >> index;
                if (index < 0) break;

                if (index >= sll.length)
                    cout << "Error: Index out of bounds" << endl;

            } while (index >= sll.length);

            sll.removeAtIndex(index);
            cout << "Element at Index " << index << " Removed" << endl;
        }

        char w;
        cout << "Continue..." << endl;
        cin.ignore();
        cin.get(w);

    } while (menu != 0);
    return 0;
}