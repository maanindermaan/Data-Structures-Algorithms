#include <iostream>
#include <vector>
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

// // Approach 1 -> very good TC
// int miniHelper(vector<int> indexArray) {
    //     int mini = INT_MAX;
    //     for (int i = 1; i < indexArray.size(); i++) {
    //         mini = min(mini, indexArray[i] - indexArray[i - 1]);
    //     }
    //     return mini;
    // }

    // vector<int> nodesBetweenCriticalPoints(Node* head) {
    //     vector<int> indexArray;
    //     Node* prev = head;
    //     Node* curr = head->next;

    //     int index = 1;
    //     while (curr != NULL && curr->next != NULL) {
    //         if ((prev->data < curr->data && curr->data > curr->next->data) || 
    //             (prev->data > curr->data && curr->data < curr->next->data)) {
    //             indexArray.push_back(index);
    //         }
    //         prev = curr;
    //         curr = curr->next;
    //         index++;
    //     }

    //     if (indexArray.size() < 2) {
    //         return {-1, -1};
    //     } else {
    //         int mini = miniHelper(indexArray);
    //         int maxi = indexArray.back() - indexArray.front();

    //         return {mini, maxi};
    //     }
    // }




// Approach 2
vector<int> minimumAndMaximumNodesBetweenCriticalPoints(Node *&head)
{
    // storing minDistance and maxDistance
    vector<int> ans(2); // create a vector with size 2
    ans[0] = -1;        // assign value to the first element
    ans[1] = -1;        // assign value to the second element

    // step 1 : safe conditions
    Node *prev = head;
    if (prev == NULL)
    {
        return ans;
    }
    Node *curr = head->next;
    if (curr == NULL)
    {
        return ans;
    }
    Node *nextNode = head->next->next;
    if (nextNode == NULL)
    {
        return ans;
    }

    // step 2: Finding minimum Distance
    int firstCP = -1;
    int lastCP = -1;
    int minDistance = INT_MAX;
    int i = 1;
    while (nextNode != NULL)
    {
        // Ab hum dekhlenge ki kya vo point local maxima hai ya local minima hai
        bool isCP = false;
        if (((curr->data > prev->data) && (curr->data > nextNode->data)) || ((curr->data < prev->data) && (curr->data < nextNode->data)))
        {
            isCP = true;
        }

        // Ye to sirf pehli CP ke liye hai baaki
        if (isCP && firstCP == -1)
        {
            firstCP = i;
            lastCP = i;
        }
        // BAAKI saare CP yha jayenge
        else if (isCP)
        {
            minDistance = min(minDistance, i - lastCP);
            lastCP = i;
        }
        ++i;
        prev = prev->next;
        curr = curr->next;
        nextNode = nextNode->next;
    }
    // step 3 : Assigning min and max distance to ans array
    // this means only ek hi CP tha kyunki last update nahi hua
    if (lastCP == firstCP)
    {
        return ans;
    }

    else
    {
        ans[0] = minDistance;
        int maxDistance = lastCP - firstCP;
        ans[1] = maxDistance;
    }
    return ans;
}

int main()
{
    Node *head = new Node(5);
    Node *second = new Node(3);
    Node *third = new Node(1);
    Node *fourth = new Node(2);
    Node *fifth = new Node(5);
    Node *sixth = new Node(1);
    Node *seventh = new Node(2);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = sixth;
    sixth->next = seventh;
    seventh->next = NULL;

    vector<int> ans = minimumAndMaximumNodesBetweenCriticalPoints(head);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}
