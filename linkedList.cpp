#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;

    node(int val){
        data = val;
        next = NULL;
    }
};

void insertAtHead(node* &head, int val){
    node* n = new node(val);
    n->next = head;
    head = n; 
}

void insertAtTail(node* &head, int val){
    node* n = new node(val);

    if(head == NULL){
        head = n;
        return;
    }

    node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = n;
}

void insertionAfter(node* &head, int key, int val){
    node* n = new node(val);

    if(head == NULL){
        head = n;
        return;
    }

    if(head->next == NULL){
        head->next = n;
        return;
    }

    node* temp = head;

    while(temp->data != key){
        temp = temp->next;
    }
    n->next = temp->next;
    temp->next = n;
}

void insertBefore(node* &head, int key, int val){
    node* n = new node(val);
    if(head == NULL){
        head = n;
        return;
    }

    if(head->next == NULL){
        n->next = head;
        n = head;
        return;
    }
    node* temp = head;
    while(temp->next->data != key){
        temp = temp->next;
    } 
    n->next = temp->next;
    temp->next = n;
}

void deletionBefore(node* &head, int key){
    node* temp = head;

    if(head == NULL){
        return;
    }

    if(head->next == NULL){
        node* temp = head;
        head = head->next;
        delete temp;
    }

    while(temp->next->next->data != key){
        temp = temp->next;
    }
    node* todelete = temp->next;
    temp->next = temp->next->next;
    delete todelete;
}

node* Search(node* &head, int key){
    node* temp = head;

    while(temp!=NULL){
        if(temp->data == key){
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

void deleteEntire(node* &head){
    if(head == NULL){
        return;
    }

    node* temp = head;
    while(temp != NULL){
        node* todelete = temp;
        head = head->next;
        temp = temp->next;
        delete todelete;
    }
}

void display(node* head){
    node* temp = head;
    while(temp != NULL){
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

bool search(node* head, int key){
    node* temp = head;
    while(temp != NULL){
        if(temp->data == key){
            return true;
        }
        temp = temp->next;
    }
    return false;
}

int main(){
    node* head = NULL;
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    display(head);
    insertAtHead(head, 4);
    insertionAfter(head,2,5);
    insertBefore(head, 5, 6);
    deletionBefore(head, 2);
    display(head);
    node* ans = Search(head, 5);
    cout << ans->data << endl;
    return 0;
}