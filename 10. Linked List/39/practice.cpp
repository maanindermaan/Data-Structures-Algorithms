#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *prev;
    Node *next;

    Node()
    {
        this->data = 0;
        this->prev = NULL;
        this->next = NULL;
    }

    Node(int data)
    {
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }

    ~Node(){
        cout<<"Node with value "<<this->data<<" is deleted"<<endl;
    }
};

void print(Node *&tail)
{
    Node *temp = tail;

    do{
        cout << temp->data << " ";
        temp = temp->next;
    }while(temp != tail);

}

void insertAtValue(int value , int data , Node* &tail){
    // empty list
    if(tail == NULL){
        Node* newNode = new Node(data);
        tail = newNode;
        newNode->next = newNode;
        newNode->prev = newNode;
    }
    else{
        Node* prevNode = tail;
        Node* currNode = new Node(data);

        while(prevNode->data != value){
            prevNode = prevNode->next;
        }
        Node* nextNode = prevNode->next;

        prevNode->next = currNode;
        currNode->prev = prevNode;

        currNode->next = nextNode;
        nextNode->prev = currNode;
    }
}   


void deleteNode(Node* &tail , int value){
    if(tail == NULL){
        cout<<"ERROR 404"<<endl;
    }
    else{
        Node* prevNode = tail;
        Node* currNode = prevNode->next;
        while(currNode->data != value){
            prevNode = currNode;
            currNode = currNode->next;
        }
        Node* nextNode = currNode->next;

        prevNode->next = nextNode;
        nextNode->prev = prevNode;

        currNode->next = NULL;
        currNode->prev = NULL;

        delete currNode; 
        return;
    }
}

int main()
{
    Node* tail = NULL;

    insertAtValue(10 , 1 , tail);
    insertAtValue(1 , 4 , tail);
    insertAtValue(4 , 6 , tail);
    insertAtValue(1 , 2 , tail);
    insertAtValue(2 , 3 , tail);
    insertAtValue(4 , 5 , tail);
    insertAtValue(6 , 10 , tail);
    insertAtValue(6 , 7 , tail);
    insertAtValue(7 , 8 , tail);
    insertAtValue(8 , 9 , tail);
    print(tail);


    cout<<endl;
    cout<<endl;
    cout<<endl;
    deleteNode(tail , 5);

    print(tail);
    return 0;
}