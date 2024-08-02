// Approach - 1
// #include <iostream>
// using namespace std;

// class Node
// {
// public:
//     int data;
//     Node *next;

//     Node()
//     {
//         this->data = 0;
//         this->next = NULL;
//     }

//     Node(int data)
//     {
//         this->data = data;
//         this->next = NULL;
//     }
// };

// void print(Node *head)
// {
//     Node *temp = head;
//     while (temp != NULL)
//     {
//         cout << temp->data << " ";
//         temp = temp->next;
//     }
//     cout << endl;
// }

// int findLen(Node *head)
// {
//     Node *temp = head;
//     int count = 0;
//     while (temp != NULL)
//     {
//         temp = temp->next;
//         count++;
//     }
//     return count;
// }

// void kthElementFromEnd(Node *head, int k)
// {
//     int len = findLen(head);
    
//     int ans = len - k;

//     if (ans < 0)
//     {
//         cout << "Error: k is greater than the length of the linked list" << endl;
//         return;
//     }

//     Node *temp = head;
//     for (int i = 0; i < ans; i++)
//     {
//         temp = temp->next;
//     }

//     cout << "Kth element from end is: " << temp->data << endl;
// }

// int main()
// {
//     Node *head = new Node(10);
//     Node *second = new Node(20);
//     Node *third = new Node(30);
//     Node *fourth = new Node(40);
//     Node *fifth = new Node(50);
//     Node *sixth = new Node(60);
//     Node *seventh = new Node(70);
//     Node *eight = new Node(80);
//     Node *ninth = new Node(90);
//     Node *tenth = new Node(100);

//     head->next = second;
//     second->next = third;
//     third->next = fourth;
//     fourth->next = fifth;
//     fifth->next = sixth;
//     sixth->next = seventh;
//     seventh->next = eight;
//     eight->next = ninth;
//     ninth->next = tenth;
//     tenth->next = NULL;

//     cout << "The Linked list is: " << endl;
//     print(head);
//     cout << endl;

//     int k;
//     cout << "Enter the value of K: ";
//     cin >> k;
//     cout << endl;

//     kthElementFromEnd(head, k);

//     return 0;
// }




























// Approach - 2
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

void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void kthElementFromEnd(Node* &head , int k){
    Node* fast = head;
    Node* slow = head;

    // Move the fast pointer 'k' nodes ahead of the slow pointer
    for (int i = 0; i < k; i++) {
        if (fast == NULL) {
            cout << "Error: k is greater than the length of the linked list" << endl;
            return;
        }
        fast = fast->next;
    }

    // Move both pointers at the same pace until the fast pointer reaches the end
    while (fast != NULL) {
        fast = fast->next;
        slow = slow->next;
    }

    // At this point, the slow pointer is at the kth node from the end
    cout << "Kth element from end is: " << slow->data << endl;
}


int main()
{
    Node *head = new Node(10);
    Node *second = new Node(20);
    Node *third = new Node(30);
    Node *fourth = new Node(40);
    Node *fifth = new Node(50);
    Node *sixth = new Node(60);
    Node *seventh = new Node(70);
    Node *eight = new Node(80);
    Node *ninth = new Node(90);
    Node *tenth = new Node(100);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = sixth;
    sixth->next = seventh;
    seventh->next = eight;
    eight->next = ninth;
    ninth->next = tenth;
    tenth->next = NULL;

    cout << "The Linked list is: " << endl;
    print(head);
    cout << endl;

    int k;
    cout << "Enter the value of K: ";
    cin >> k;
    cout << endl;

    kthElementFromEnd(head, k);

    return 0;
}




