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

    void print(Node* &head){
        Node* temp = head;

        while(temp!=NULL){
            cout<<temp->data<<"->";
            temp = temp->next; // pointer aage badadia
        }
    }
    
};

    void push(Node* &head , Node* &tail , int data){ 
        // Step 1 -> create a new node
        Node* newNode = new Node(data);
    
        // Step 2 -> 
        newNode->next = head;
    
        // Step 3 -> 
        // first node
        if(head == NULL){
            // -> empty list , first node ab add hogi
            tail = newNode;
        }
        head = newNode;
    }
    
    void top(Node* root){
        if(root == NULL){
            cout<<"Sorry nothing to show "<<endl;
            return;
        }
        cout<<"Top of the stack contains : "<<root->data;
        return;
    }
    
    void pop(Node* &head , Node* &tail){
        // No element case
        if(head == NULL){
            cout<<" NOTHING TO POP "<<endl;
            return;
        }
        
        // single element case
        if(head == tail || head->next == NULL){
            head = NULL;
            tail = NULL;
            cout<<endl;
            cout<<"Single element and now it;s deleted"<<endl;
            return;
        }
        
        // multiple element case
        Node* curr = head->next;
        head->next = NULL;
        head = curr;
        return;
    }
    
    int findLength(Node* head , Node* tail){
        int ans = 0;
        while(head != NULL){
            head = head->next;
            ans++;
        }
        return ans;
    }
    
    
    

int main(){
    Node* head = NULL;
    Node* tail = NULL;
    push(head , tail , 20);
    push(head , tail , 30);
    push(head , tail , 40);
    // push(head , tail , 50);
    // push(head , tail , 60);
    

    cout<<"Printing the Stack Elements"<<endl;
    
    int ans = findLength(head , tail);
    cout<<"Length of Stack is : "<<ans<<endl;
    head->print(head);
    cout<<endl;
    top(head);
    
    pop(head , tail);
    cout<<endl;
    top(head);
    
    pop(head , tail);
    cout<<endl;
    top(head);
    
    pop(head , tail);
    cout<<endl;
    top(head);
    
    pop(head , tail);
    cout<<endl;
    top(head);
return 0;
}