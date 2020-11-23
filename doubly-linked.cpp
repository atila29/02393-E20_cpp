#include "doubly-linked.h"

List::~List(void) {

}

List::List(void) {
    this->first = nullptr;

}

void List::print(void) {
    Node *current = first;

    if(current == nullptr)
        return;

    while(current->next != nullptr) {


        std::cout << current->val << " ";

        current = current->next;
    }
    std::cout << current->val <<  std::endl;
}

void List::reverse(void) {
    Node* current = first;
    Node *prev = nullptr;
    Node *next = nullptr;

    while (current != nullptr) {

        next = current->next;

        current->next = prev;

        prev = current;
        current = next;
    }
    first = prev;

}

void List::insert(int n) {
    Node *node = new Node;
    node->val = n;

    if(first==nullptr) {
        first = node;
        return;
    }

    Node *current = first;

    while(current->next != nullptr) {
        current = current->next;
    }
    current->next = node;

}

