#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        this->next = NULL;
    }
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

// bool isCircular(Node *head)
// {
//     Node *temp = head->next;
//     while(temp != NULL){
//         if(temp == head){
//             return true;
//         }
//         temp = temp->next;
//     }
//     return false;
// }

// bool isCircular(Node *&head)
// {
//     Node *current = head;

//     while (current != NULL)
//     {
//         if (current->next == head)
//         {
//             return true;
//         }
//         Node *temp = current->next;
//         current->next = head;
//         current = temp;
//     }

//     return false;
// }

// bool isCircular(Node* head) {
//     Node* temp = head;

//     // Traverse the linked list
//     while (temp->next != NULL && temp->next != head) {
//         temp = temp->next;
//     }

//     // If we reached the end of the list, it is not circular
//     if (temp->next == NULL) {
//         return false;
//     }

//     // If we found the head again, it is circular
//     return true;
// }


bool isCircular(Node* head){
    Node* slow = head;
    Node* fast = head;

    while(fast != NULL){
        fast = fast->next;
        if(fast != NULL){
            fast = fast->next;
            slow = slow->next;
        }
        if(fast == slow){
            return true;
            break;
        }
    }
    return false;
}

int main()
{
    Node *head = new Node(10);
    Node *first = new Node(20);
    Node *second = new Node(30);
    Node *third = new Node(40);
    Node *fourth = new Node(50);
    Node *fifth = new Node(60);

    head->next = first;
    first->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    // fifth->next = first;

    cout << "The loop is circular: " << isCircular(head) << endl;

    return 0;
}