#include<iostream>
using namespace std;

struct node {
    int data;
    node *next;
    node *prev;
    node(int data) {
        this->data = data;
        next = NULL;
        prev = NULL;
    }
};

void insertAtEnd(struct node *&head, int data) {
    struct node *newNode = new node(data);
    if(head == NULL) {
        head = newNode;
        newNode->next = head;
        newNode->prev = head;
    }
    else {
        struct node *temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
        newNode->next = head;
        head->prev = newNode;
    }
    cout << newNode->data << " is inserted\n";
}

void printLinkedList(struct node *head) {
    if(head == NULL) {
        cout << "No node is here ! \n";
        return;
    }
    else {
        struct node *temp = head;
        cout << "The Linked List is :-\n";
        while (temp->next != head) 
        {
            cout << temp->data << "\t";
            temp = temp->next;
        }
        cout << temp->data << "\n";

        cout << "The Reverse Linked List :-" << "\n";
        while (temp != head)
        {
            cout << temp->data << "\t";
            temp = temp->prev;
        }
        cout << temp->data << "\n";  
    }
}

int main() {
    cout << "Traversal in ccircular doubly linked list :-\n";

    struct node *head = NULL;
    insertAtEnd(head, 14);
    insertAtEnd(head, 16);
    insertAtEnd(head, 20);
    insertAtEnd(head, 24);
    insertAtEnd(head, 45);

    printLinkedList(head);
}