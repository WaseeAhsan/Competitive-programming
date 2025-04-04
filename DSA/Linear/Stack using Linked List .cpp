#include<bits/stdc++.h>
using namespace std; 

struct Node
{
    int data ; 
    Node* next ; 
};

class Stack
{
private: 
    Node* top ;

public:
    Stack()
    {
        top = nullptr ; 
    }

    void push(int value)
    {
        Node* newValue = new Node() ;
        newValue->data = value ; 
        newValue->next = top ; 
        top = newValue ; 
        cout << value << " pushed to stack" << endl; 
    }
      bool isEmpty() {
        return top == nullptr;
    }
    void pop()
    {
        if(isEmpty())
        {
            cout << " stack is empty . cannot pop " << endl; 
        }

        Node* temp = top ; 
        top = top->next ; 
        cout << temp->data << " popped from stack" <<endl ; 
        delete temp; 
    }
     int peek() {
        if (isEmpty()) {
            cout << "Stack is empty.\n";
            return -1;
        }
        return top->data;
    }
      ~Stack() {
        while (!isEmpty()) {
            pop();
        }
    }

};


int main()
{
      Stack s;

    s.push(10);
    s.push(20);
    s.push(30);

    cout << "Top element is: " << s.peek() << "\n";

    s.pop();
    s.pop();

    cout << "Top element is now: " << s.peek() << "\n";

    s.pop();
    s.pop(); // extra pop to test empty stack
    return 0 ; 
}