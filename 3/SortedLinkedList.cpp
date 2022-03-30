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

class SortedLinkedList {
 public:
  Node *head = NULL;
  Node *tail = NULL;
  int length = 0;

  void add(int i) {
    Node *newNode = new Node(i);
    Node *temp = head;

    // if linkedlist is empty
    if (head == NULL) {
      head = newNode;
      tail = newNode;
      length++;
      return;
    }

    while (temp != NULL) {
      // traversing until we find the greatest
      if (i < temp->data) {
        // it isn't the first element
        if (temp->prev != NULL) {
          temp->prev->next = newNode;
          newNode->next = temp;
          newNode->prev = temp->prev;
          temp->prev = newNode;
        }
        // it is  the first element
        else {
          newNode->next = temp;
          temp->prev = newNode;
          head = newNode;
        }
        length++;
        return;
      }

      if (temp->next == NULL) {
        break;
      }

      temp = temp->next;
    }
    // if it is the largest element
    temp->next = newNode;
    newNode->prev = temp;
    tail = newNode;
    length++;
  }

  void pop_front() {
    // check if there is element next to the head
    if (head->next != NULL) {
      head = head->next;
      head->prev = NULL;
    } else {
      head = head->next;
      tail = tail->prev;
    }
    length--;
  }

  void pop_back() {
    // if list contains one element
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
      // search for the element
      if (ele == temp->data) {
        // if it is not the first element
        if (temp->prev != NULL) {
          temp->prev->next = temp->next;
          // if it is not the last element
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

  friend ostream &operator<<(ostream &os, const SortedLinkedList &sll) {
    sll.print(os);
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
   * Linear Search on Linked List,
   * the first index element found on.
   * if element is not found returns -1
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
  SortedLinkedList sll;

  // add Elemets
  sll.add(3);
  sll.add(1);
  sll.add(2);
  sll.add(2);
  sll.add(5);
  sll.add(2);

  // print linkedlist
  cout << sll << endl;

  // get element
  cout << "At Index 1: " << sll[1] << endl;
  cout << "At Index 4: " << sll[4] << endl;

  // access the length
  cout << "Length: " << sll.length << endl;

  // Search element
  cout << "Index of 3: " << sll.search(3) << endl;

  // remove elements
  sll.pop_front();
  sll.pop_back();
  sll.remove(2);
  cout << sll << endl;

  return 0;
}
