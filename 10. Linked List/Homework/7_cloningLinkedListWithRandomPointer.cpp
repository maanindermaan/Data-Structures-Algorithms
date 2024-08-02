// #include <iostream>
// #include <unordered_map>
// using namespace std;

// class Node
// {
// public:
//     int data;
//     Node *next;
//     Node *random;

//     Node()
//     {
//         this->data = 0;
//         this->next = NULL;
//         this->random = NULL;
//     }

//     Node(int data)
//     {
//         this->data = data;
//         this->next = NULL;
//         this->random = NULL;
//     }
// };

// void printNext(Node *head)
// {
//     Node *temp = head;
//     while (temp != NULL)
//     {
//         cout << temp->data << " ";
//         temp = temp->next;
//     }
//     cout << endl;
// }

// Node* helper(Node* head , unordered_map<Node* , Node*>&map){
//     if(head == NULL){
//         return NULL;
//     }

//     // step 1 : Make new node
//     Node* newHead = new Node(head->data);

//     // step 2 : Storing entry of old Node pointer -> new Node Pointer
//     map[head] = newHead;
 
//     // step 3 : new Node ke aage ki map ki entries recursion dekh lega (NEXT pointers)
//     newHead->next = helper(head->next, map);

//     // step 4 : poiting random pointers in newNode;
//     newHead->random = map[head->random];

//     return newHead;
// }

// Node* copyRandomList(Node* head){
//     unordered_map<Node* , Node*> map; // oldNode -> newNode ki MAPPING
//     return helper(head , map);
// }

// int main()
// {
//     Node *head = new Node(7);
//     Node *second = new Node(13);
//     Node *third = new Node(11);
//     Node *fourth = new Node(10);
//     Node *fifth = new Node(1);

//     head->next = second;
//     second->next = third;
//     third->next = fourth;
//     fourth->next = fifth;
//     fifth->next = NULL;

//     head->random = NULL;
//     second->random = head;
//     third->random = fifth;
//     fourth->random = third;
//     fifth->random = head;
//     printNext(head);

//     Node* ans = copyRandomList(head);

//     printNext(ans);
//     return 0;
// }










// WITHOUT USING MAP TO GET S.C. =  O(1)
#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *random;

    Node()
    {
        this->data = 0;
        this->next = NULL;
        this->random = NULL;
    }

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->random = NULL;
    }
};

void printNext(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

Node *copyRandomList(Node *head)
{
    if (head == NULL)
    {
        return NULL;
    }
    // Step 1 : Clone A -> A'
    Node *curr = head; // iterator over old head
    while (curr != NULL)
    {
        Node *clonedNode = new Node(curr->data);
        clonedNode->next = curr->next;
        curr->next = clonedNode;
        curr = curr->next->next;
    }

    // Step 2 : Assigning Random Links of A' with the help of oldNode A
    curr = head; // vaapis head pe le aaye
    while (curr != NULL)
    {
        Node *clonedNode = curr->next; // curr ka next hmesha cloned Node hoga
        if (curr->random != NULL)
        {
            clonedNode->random = curr->random->next;
        }
        else
        {
            clonedNode->random = NULL;
        }
        curr = curr->next->next;
    }

    // Step 3 : Detatch A' from A
    curr = head;
    Node *clonedNode = curr->next;
    while (curr != NULL && clonedNode != NULL)
    {
        Node *clonedNode = curr->next; // CloneNode at 167 has scope in 161-170 only because we have to return as well na so we take clonedNode 160 as intial point only
        curr->next = curr->next->next;
        if (clonedNode->next != NULL)
        {
            clonedNode->next = clonedNode->next->next;
        }
        curr = curr->next;
    }
    return clonedNode;
}

int main()
{
    Node *head = new Node(7);
    Node *second = new Node(13);
    Node *third = new Node(11);
    Node *fourth = new Node(10);
    Node *fifth = new Node(1);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = NULL;

    head->random = NULL;
    second->random = head;
    third->random = fifth;
    fourth->random = third;
    fifth->random = head;
    printNext(head);

    Node *ans = copyRandomList(head);

    printNext(ans);
    return 0;
}