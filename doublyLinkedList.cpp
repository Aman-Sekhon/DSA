#include<iostream>
using namespace std;

class node{
    public:
    node* previous;
    int data;
    node* next;

    node(int val){
        data = val;
        previous = NULL;
        next = NULL;
    }
};

void insertAtHead(node* &head, int val){
    node* n = new node(val);
    n->next = head;
    if(head != NULL){
        head->previous = n;
    }
    head = n;
}

void insertAfter(node* &head, int key, int val){
    node* n = new node(val);
    node* temp = head;

    while(temp->data != key){
        temp = temp->next;
    }
    temp->next->previous = n;
    n->next = temp->next;
    temp->next = n;
    n->previous = temp;
}

void insertBefore(node* &head, int key, int val){
    node* n = new node(val);
    node* temp = head;

    while(temp->data != key){
        temp = temp->next;
    }

    temp->previous->next = n;
    n->previous = temp->previous;
    temp->previous = n;
    n->next = temp;
}

void deletionBefore(node* head, int key){
    node* temp = head;

    while(temp->data != key){
        temp = temp->next;
    } 

    node* todelete = temp->previous;
    temp->previous = temp->previous->previous;
    temp->previous->next = temp;
    delete todelete;
}

void deleteAtHead(node* &head){
    node* temp = head;
    head = head->next;
    head->previous = NULL;
    delete temp;
}

void deletionAtTail(node* head){
    if(head == NULL){
        return;
    }

    if(head->next == NULL){
        node* temp = head;
        head = head->next;
        head->previous = NULL;
        delete temp;
    }

    node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->previous->next = NULL;
    delete temp;
}

void insertAtTail(node* &head, int val){
    node* n = new node(val);

    if(head == NULL){
        n->next = head;
        head = n;
        return;
    }

    node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = n;
    n->previous = temp;
}

void display(node* &head){
    node* temp = head;
    while(temp != NULL){
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main(){
    node* head = NULL;
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtTail(head, 4);
    insertAtTail(head, 5);
    insertAtTail(head, 6);
    display(head);
    insertAfter(head, 4, 7);
    insertBefore(head, 7, 8);
    deletionBefore(head, 8);
    display(head);
    return 0;
}