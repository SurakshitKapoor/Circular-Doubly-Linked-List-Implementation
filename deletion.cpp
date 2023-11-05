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
    cout << newNode->data << " is inserted \n";
}

void deleteAtEnd(struct node *&head) {
    if(head == NULL) {
        cout << "No node is here !\n";
        return;
    }
    else {
        struct node *temp = head;
        int data;
        while (temp->next != head) 
        {
            temp = temp->next;
        }
        struct node *delNode = temp;
        temp = temp->prev;
        temp->next = delNode->next;
        head->prev = temp;
        data = delNode->data;
        if(delNode == head) {
            delete delNode;
            head = NULL;
        }
        else {
            delete delNode;
        }
        cout << data << " is deleted\n";        
    }
}

void deleteAtBeginning(struct node *&head) {
    int data;
    if(head == NULL) {
        cout << "No node is here !\n";
        return;
    }
    // else if(head->next == head) {
    //     data = head->data;
    //     delete head;
    //      head = NULL;
    //  }
    else {
        struct node *temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        data = temp->next->data;
        temp->next = head->next;
        head->next->prev = temp;

        //do this or above else if method :- motine is to set head as NULL once last node will be deleted
        delete head;
        if(head->next == head) {
            head = NULL;
        }
        else {
            head = temp->next;
        }   
    }
    cout << data << " is deleted\n";
}

void deleteAtPosition(struct node *&head, int position) {
    if(position == 1) {
        deleteAtBeginning(head);
    }
    else {
        int data;
        int count = 1;
        struct node *temp = head;
        while (count < position-1)
        {
            temp = temp->next;
            count ++;
        }
        node *delNode = temp->next;
        data = delNode->data;
        temp->next = delNode->next;
        delNode->next->prev = temp;
        delete delNode;
        delNode = NULL;

        cout << data << " is deleted from " << position << " position\n";
        
    }
}

void printLinkedList(struct node *head) {
    if(head == NULL) {
        cout << "No node is here !" << endl;
        return;
    }
    else {
        struct node *temp = head;
        cout << "The linked list is :-\n";
        while (temp->next != head)
        {
            cout << temp->data << "\t";
            temp = temp->next;
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
    cout << "Deletion in circular doubly linked list :-\n";
    struct node *head = NULL;
    insertAtEnd(head, 12);
    insertAtEnd(head, 14);
    insertAtEnd(head, 16);
    insertAtEnd(head, 19);
    insertAtEnd(head, 20);

    deleteAtEnd(head);
    // deleteAtEnd(head);
    // deleteAtEnd(head);
    // deleteAtEnd(head);
    // deleteAtEnd(head);
    // deleteAtEnd(head);

    deleteAtBeginning(head);
    // deleteAtBeginning(head);
    // deleteAtBeginning(head);
    // deleteAtBeginning(head);

    deleteAtPosition(head, 3);
    printLinkedList(head);
}