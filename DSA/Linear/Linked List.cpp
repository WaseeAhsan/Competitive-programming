#include <bits/stdc++.h>
using namespace std;

class node {
public:
    int data;
    node* nxt;

    node(int val) {
        data = val;
        nxt = NULL;
    }
};

void insertAtTail(node* &head, int val) {
    node* n = new node(val);
    if (head == NULL) {
        head = n;
        return;
    }
    node* temp = head;
    while (temp->nxt != NULL) {
        temp = temp->nxt;
    }
    temp->nxt = n;
}

void insertAtHead(node* &head, int val) {
    node* n = new node(val);
    n->nxt = head;
    head = n;
}

void deleteHead(node* &head) { 
    if (head == NULL) return;
    node* temp = head;
    head = head->nxt;
    delete temp;
}

void deleteNode(node* &head, int val) {
    if (head == NULL) return;

    if (head->data == val) {
        deleteHead(head); 
        return;
    }

    node* temp = head;
    while (temp->nxt != NULL && temp->nxt->data != val) {
        temp = temp->nxt;
    }

    if (temp->nxt != NULL) {
        node* toDelete = temp->nxt;
        temp->nxt = temp->nxt->nxt;
        delete toDelete;
    }
}

void display(node* head) {
    node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->nxt;
    }
    cout << endl;
}

int main() {
    node* head = NULL;

    insertAtTail(head, 10);
    insertAtHead(head, 20);
    deleteNode(head, 10); 

    display(head); 

    return 0;
}
