#include <iostream>
#include <stack>
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

vector<int> nextLargerNodes(Node *head)
{

    vector<int> ll;
    while (head != NULL)
    {
        ll.push_back(head->data);
        head = head->next;
    }

    stack<int> s;
    vector<int> ans(ll.size()); // init 0

    for (int i = 0; i < ll.size(); i++)
    {
        while (!s.empty() && ll[i] > ll[s.top()])
        {
            // ith element is the next greater of the element index present in stack
            int index = s.top();
            s.pop();
            ans[index] = ll[i];
        }
        s.push(i);
    }

    return ans;
}

int main()
{
    Node *head = new Node(2);
    Node *second = new Node(1);
    Node *third = new Node(7);
    Node *fourth = new Node(4);
    Node *fifth = new Node(3);
    Node *sixth = new Node(5);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = sixth;

    vector<int> ans = nextLargerNodes(head);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << "  ";
    }
    return 0;
}