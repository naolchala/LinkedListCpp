#include <iostream>
#include <stdexcept>
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
    length--;
  }
}
void SinglyLinkedList::removeLast() {
  Node *temp = head;
  while (temp->next->next != NULL) temp = temp->next;
  temp->next = NULL;
  length--;
}

int main() {
  SinglyLinkedList sll;

  cout << "Adding" << endl;
  sll.addAtFirst(2);
  sll.addAtFirst(3);
  sll.addAtFirst(4);
  sll.addAtIndex(5, 3);
  sll.addAtLast(6);
  sll.print();

  cout << "Deleting " << endl;
  sll.removeLast();
  sll.removeFirst();
  sll.removeAtIndex(1);
  sll.print();

  return 0;
}