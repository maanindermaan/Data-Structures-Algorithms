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
        Node* newNode = new Node(data);

        // Step 2 -> connect with tail node
        if(tail == NULL){
            // first node ab add hone wali hai
            tail = newNode;
            head = newNode;
        }
        
        else{
            // LL is non empty 
            tail->next = newNode;
        }

        // step 3 -> update tail
        tail = newNode; 
    }
    
    void front(Node* root){
        if(root == NULL){
            cout<<"Sorry nothing to show "<<endl;
            return;
        }
        cout<<"Front of the queue contains : "<<root->data;
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
    push(head , tail , 50);
    // push(head , tail , 60);
    

    cout<<"Printing the Queue Elements"<<endl;
    
    int ans = findLength(head , tail);
    cout<<"Length of Queue is : "<<ans<<endl;
    head->print(head);
    cout<<endl;
    front(head);
    
    pop(head , tail);
    cout<<endl;
    front(head);
    
    pop(head , tail);
    cout<<endl;
    front(head);
    
    pop(head , tail);
    cout<<endl;
    front(head);
    
    pop(head , tail);
    cout<<endl;
    front(head);
return 0;
}