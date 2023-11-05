#include<iostream>
using namespace std;

struct node
{
    int data;
    node *next;
    node *prev;
    node(int data) {
        this->data = data;
        next = NULL;
        prev = NULL;
    }
};

void insertAtBeginning(struct node *&head, int data) {
    struct node *newNode = new node(data);

    if(head == NULL) {
        head = newNode;
        newNode->prev = head;
        newNode->next = head;
    }
    else {
        struct node *temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        } 
        temp->next = newNode;
        newNode->next = head;
        newNode->prev = head->prev;
        head->prev = newNode;
        head = newNode;
    }
    cout << newNode->data << " is inserted \n";
}

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
    cout << newNode->data << " is inserted \n";
}

void insertAtPosition(struct node *&head, int data, int position) {
    struct node *newNode = new node(data);
    if(position == 1) {
        insertAtBeginning(head, data);
    }
    else {
        struct node *temp = head;
        int count = 1;
        while (count < position-1)
        {
            temp = temp->next;
            count ++;
        }
        temp->next->prev = newNode;
        newNode->next = temp->next;
        newNode->prev = temp;
        temp->next = newNode;  
    }
    cout << newNode->data << " is inserted at " << position << " position\n";
}

void printLinkedList(struct node *&head) {
    if (head == NULL)
    {
        cout << "No node is here ! \n";
        return;
    }
    else {
        struct node *temp = head;
        cout << "The Linked List is :- \n";
        while (temp->next != head)
        {
            cout << temp->data << "\t";
            temp = temp->next;
        }
        cout << temp->data << "\n";

        cout << "Reverse Linked List is :-\n"; 
        while (temp != head)
        {
            cout << temp->data << "\t";
            temp = temp->prev;
        }
        cout << temp->data << "\n";
        // cout << temp->prev->data << "\n";
        // cout << temp->prev->prev->data << "\n";
        // cout << temp->prev->prev->prev->data << "\n";
        // cout << temp->prev->prev->prev->prev->data << "\n";
    }
    
}
int main() {
    cout << "Insertion in circular doubly lnked list :-\n";

    struct node *head = NULL;
    insertAtBeginning(head, 25);
    insertAtBeginning(head, 31);
    insertAtBeginning(head, 52);

    insertAtEnd(head, 12);
    insertAtEnd(head, 15);
    insertAtEnd(head, 18);

    insertAtPosition(head, 71, 1);

    printLinkedList(head);
}