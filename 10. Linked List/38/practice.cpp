#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(){
        this->data = 0;
        this->next = NULL;
    }
    Node(int data){
        this->data = data;
        this->next = NULL;
    }

    ~Node(){
        // Write a destructor to delete a node
        cout<<"Node with value "<<this->data<<" is deleted.";
    }
};



void insertAtValue(int value , int data , Node* &tail){
    if(tail == NULL){
        Node* newNode = new Node(data);
        tail = newNode;
        newNode -> next = newNode;
    }
    else{
        Node* curr = tail;
        while(curr->data != value){
            curr = curr->next;
        }
        Node* newNode = new Node(data);

        newNode->next = curr->next;
        curr->next = newNode;
    }
}

void deleteNode(int value , Node* &tail){
    if(tail == NULL){
        cout<<"Empty NODE"<<endl;
    }
    else{
        Node* prev = tail;
        Node* curr = prev->next;
        while(curr->data != value){
            prev = curr;
            curr = curr->next;
        }
        prev->next = curr->next;
        if(tail == curr){
            tail = prev;
        }
        curr->next = NULL;
        delete curr;
    }
}



void print(Node* &tail){
    Node* temp = tail;
    // cout<<tail->data<<" ";
    // while(tail->next != temp){
    //     cout<<tail->data<<" ";
    //     tail = tail->next;
    // }

    do
    {
        cout<<tail->data<<" ";
        tail = tail->next;
    } while(tail != temp);
    
}







int main(){
    Node* tail = NULL;

    insertAtValue(6,10,tail);
    insertAtValue(10,15,tail);
    insertAtValue(10,5,tail);
    insertAtValue(15,20,tail);
    print(tail);

    deleteNode(10 , tail);
    print(tail);
return 0;
}