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

int findLen(Node *head)
{
    Node *temp = head;
    int count = 0;
    while (temp != NULL)
    {
        temp = temp->next;
        count++;
    }
    return count;
}

void print(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Method - 1
    Node *rotatedList(Node *&head, int k){
        if(head == nullptr || k <= 0) {
            return head;
        }

        int len = findLen(head);
        k = k % len;
        if(k == 0) {
            return head;
        }

        Node* tail = head;
        while(tail->next != nullptr) {
            tail = tail->next;
        }

        int req = len - k - 1;
        Node* temp = head;
        while(req--) {
            temp = temp->next;
        }

        Node* curr = temp->next;
        temp->next = nullptr;
        tail->next = head;
        head = curr;

        return head;
    }


// Method - 2
Node *rotatedList(Node *&head, int k)
{
    Node *curr = head;
    Node *tail = head;
    Node *prev = NULL;

    int len = findLen(head);

    k = k%len;

    int skip = len - k;
    int count = 0;

    if (head == NULL)
    {
        cout << "Cannot rotate empty list";
        return NULL;
    }

    else if (k == len || k==0)
    {
        return head;
    }

    else if (k < len)
    {

        while (tail->next != NULL)
        {
            tail = tail->next;
        }

        while (count < skip && curr != NULL)
        {
            prev = curr;
            curr = curr->next;
            count++;
        }
        // Now curr is at position where we want to exxagerate

        tail->next = head;
        prev->next = NULL;

        head = curr;
    }
    return head;
}

int main()
{
    Node *head = new Node(1);
    Node *second = new Node(2);
    Node *third = new Node(3);
    Node *fourth = new Node(4);
    Node *fifth = new Node(5);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = NULL;

    int k;
    cout << "Enter the number of elements you want to rotate : ";
    cin >> k;

    Node *ans = rotatedList(head, k);

    print(ans);

    return 0;
}
