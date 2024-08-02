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

Node *midNode(Node *head)
{
    Node *slow = head;
    Node *fast = head->next;

    while (fast != NULL)
    {
        fast = fast->next;
        while(fast !=NULL){
            fast = fast->next;
            slow = slow->next;
        }   
    }
    return slow;
}

Node *merge(Node *left, Node *right)
{
    Node *ans = new Node(-1);
    Node *mptr = ans;
    if (left == NULL)
    {
        return right;
    }

    if (right == NULL)
    {
        return left;
    }

    while (left != NULL && right != NULL)
    {
        if (left->data <= right->data)
        {
            mptr->next = left;
            mptr = left;
            left = left->next;
        }
        else
        {
            mptr->next = right;
            mptr = right;
            right = right->next;
        }
    }

    // Append remaining elements from left or right list
    if (left != NULL)
    {
        mptr->next = left;
    }
    else if (right != NULL)
    {
        mptr->next = right;
    }

    return ans->next;
}
Node *mergeSortInLinkedList(Node *&head)
{
    // step 1 : Base Case
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    // step 2 : Break LL into two Halves using mid
    Node *mid = midNode(head);
    Node *left = head;
    Node *right = mid->next;
    mid->next = NULL; // step 3 : humne list ko tod diya

    // step 4 : Sort Recursively
    left = mergeSortInLinkedList(left);
    right = mergeSortInLinkedList(right);

    // step 5 : Merge these sorted LL now
    Node* finalAns = merge(left, right);

    return finalAns;
}

int main()
{
    Node *head = new Node(90);
    Node *second = new Node(100);
    Node *third = new Node(80);
    Node *fourth = new Node(50);
    Node *fifth = new Node(70);
    Node *sixth = new Node(60);
    Node *seventh = new Node(20);
    Node *eight = new Node(10);
    Node *ninth = new Node(30);
    Node *tenth = new Node(40);

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

    Node* ans = mergeSortInLinkedList(head);
    print(ans);
    return 0;
}




