#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node* bottom;

    Node()
    {
        this->data = 0;
        this->next = NULL;
        this->bottom = NULL;
    }

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->bottom = NULL;
    }
};

// Priting using bottom
void printFlattened(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->bottom;
    }
    cout << endl;
}

// Recursive Merge Code using bottom pointer
Node*  merge(Node* a , Node* b){
    Node* ans = NULL;
    if(a == NULL){
        return b;
    }

    if(b == NULL){
        return a;
    }

    if(a->data < b->data){
        ans = a;
        a->bottom = merge(a->bottom , b);
    }
    else{
        ans = b;
        b->bottom = merge(a , b->bottom);
    }
    return ans;
}

Node* flattenLL(Node* head){
    if(head == NULL){
        return 0;
    }

    Node* mergedLL = merge(head , flattenLL(head->next)); // this code merges last 2 L.L. So that we dont have to preserve the pointer. because if we merges first 2 L.L. then 10->19 but we actually want 5->19 so this will be error.
    return mergedLL;
}

    int main() {

    Node* head = new Node(5);
    Node* second = new Node(10);
    Node* third = new Node(19);
    Node* fourth = new Node(28);

    Node* head1 = new Node(7);
    Node* head2 = new Node(8);
    Node* head3 = new Node(30);

    Node* second1 = new Node(20);

    Node* third1 = new Node(22);
    Node* third2 = new Node(50);

    Node* fourth1 = new Node(35);
    Node* fourth2 = new Node(40);
    Node* fourth3 = new Node(45);

    head->next = second;
    second->next = third;
    third->next = fourth;

    head->bottom = head1;
    head1->bottom = head2;
    head2->bottom = head3;

    second->bottom = second1;

    third->bottom = third1;
    third1->bottom = third2;

    fourth->bottom = fourth1;
    fourth1->bottom = fourth2;
    fourth2->bottom = fourth3;

    // Flatten the linked list
    Node* flattened = flattenLL(head);

    // Print the flattened linked list
    printFlattened(flattened);
return 0;
}