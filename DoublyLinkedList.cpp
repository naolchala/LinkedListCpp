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

class DoublyLinkedList {
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

void DoublyLinkedList::print() {
  Node *temp = head;
  while (temp != NULL) {
    cout << temp->data;
    temp = temp->next;
    if (temp != NULL) {
      cout << " <-> ";
    }
  }

  cout << endl;
}
void DoublyLinkedList::addAtFirst(int data) {
  Node *newNode = new Node(data);
  Node *temp = head;
  newNode->next = temp;
  if (temp != NULL) temp->prev = newNode;
  head = newNode;
  length++;
};
void DoublyLinkedList::addAtIndex(int data, int index) {
  if (index == 0) {
    addAtFirst(data);
    return;
  } else if (index > length) {
    throw out_of_range("Index Out of Bounds");
    return;
  }

  int i = 0;
  Node *temp = head;

  while (temp != NULL && i < index - 1) {
    temp = temp->next;
    i++;
  }

  Node *newNode = new Node(data);
  Node *next = temp->next;
  next->prev = newNode;
  newNode->next = next;
  newNode->prev = temp;
  temp->next = newNode;
  length++;
};

void DoublyLinkedList::addAtLast(int data) {
  Node *newNode = new Node(data);
  Node *temp = head;

  while (temp->next != NULL) temp = temp->next;

  temp->next = newNode;
  newNode->prev = temp;
  length++;
};

void DoublyLinkedList::removeFirst() {
  head = head->next;
  head->prev = NULL;
  length--;
}
void DoublyLinkedList::removeAtIndex(int index) {
  if (index == 0)
    removeFirst();
  else if (index >= length - 1) {
    throw out_of_range("Index Out Of Bounds");
    return;
  } else {
    int i = 0;
    Node *temp = head;
    while (temp != NULL && i < index - 1) {
      temp = temp->next;
      i++;
    }
    temp->next = temp->next->next;
    temp->next->prev = temp;
    length--;
  }
}

void DoublyLinkedList::removeLast() {
  if (head != NULL) {
    Node *temp = head;
    while (temp->next->next != NULL) temp = temp->next;
    temp->next = NULL;
    length--;
  }
}

int main() {
  DoublyLinkedList dll;
  cout << "Adding" << endl;
  dll.addAtFirst(2);
  dll.addAtFirst(3);
  dll.addAtFirst(4);
  dll.addAtIndex(5, 2);
  dll.addAtLast(6);
  cout << "List Size: " << dll.length << endl;
  dll.print();

  cout << endl << "Deleting " << endl;
  dll.removeLast();
  dll.removeFirst();
  dll.removeAtIndex(1);
  cout << "List Size: " << dll.length << endl;
  dll.print();

  return 0;
}