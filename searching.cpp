#include<iostream>
using namespace std;

struct node {
    int data;
    node *prev;
    node *next;
    node (int data) {
        this->data = data;
        next = NULL;
        prev = NULL;
    }
};

void insertAtEnd(struct node *&head, int data) {
    struct node *newNode = new node(data) ;

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
        head->prev = temp; 
    }
    cout << newNode->data << " is inserted\n";
}

void searchInLinkedList(struct node *&head, int data) {
    if(head == NULL) {
        cout << "No node is here !\n";
        return;
    }
    else {
        struct node *temp = head;
        int position = 1;
        while (temp->next != head)
        {
            if(temp->data == data) {
                cout << data << " is found at position " << position << endl;
                return;
            }
            temp = temp->next;
            position ++;
        }
        //when we are on last node
        if(temp->data == data) {
            cout << data << " is found at position " << position << endl;
        } 
        else {
            cout << data << " is not found\n";
        }
        
    }
}
void printLinkedList(struct node *&head) {
    if(head == NULL) {
        cout << "No node is here !\n";
        return;
    }
    else {
        struct node *temp = head;
        cout << "The Linked List is :-\n";
        while (temp->next != head)
        {
            cout << temp->data << "\t";
            temp = temp->next ;
        }
        cout << temp->data << "\n";

        cout << "The Reverse Linked List is :-\n";
        while (temp != head)
        {
            cout << temp->data << "\t";
            temp = temp->prev;
        }
        cout << temp->data << "\n";
        
    }
}

int main() {
    cout << "Searching in circular doubly linked list :-\n";

    struct node *head = NULL;
    insertAtEnd(head, 12);
    insertAtEnd(head, 15);
    insertAtEnd(head, 24);
    insertAtEnd(head, 36);

    printLinkedList(head);

    searchInLinkedList(head, 41);
    searchInLinkedList(head, 36);
}