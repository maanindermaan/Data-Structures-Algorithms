// #include <iostream>
// #include <queue>
// #include <unordered_map>
// using namespace std;

// class Node
// {
// public:
//     char data;
//     int count;

//     Node(char data, int count)
//     {
//         this->data = data;
//         this->count = count;
//     }
// };

// class compare
// {
// public:
//     bool operator()(Node *a, Node *b)
//     {
//         return a->count < b->count;
//     }
// };

// string longestDiverseString(int a, int b, int c)
// {

//     // 1. Max Heap banalo
//     priority_queue<Node *, vector<Node *>, compare> maxHeap;

//     // 2. Push elements into Max Heap
//     if (a > 0)
//     {
//         Node *temp = new Node('a', a); // a a times -> if a = 5, -> a five times (aaaaa)
//         maxHeap.push(temp);
//     }
//     if (b > 0)
//     {
//         Node *temp = new Node('b', b);
//         maxHeap.push(temp);
//     }
//     if (c > 0)
//     {
//         Node *temp = new Node('c', c);
//         maxHeap.push(temp);
//     }

//     string ans = "";

//     while (maxHeap.size() > 1)
//     {
//         // 3. Extracting from first Element
//         Node *topFirst = maxHeap.top();
//         maxHeap.pop();
//         int topFirstCount = topFirst->count;
//         char topFirstElement = topFirst->data;

//         // 4. Extracting from Second Element
//         Node *topSecond = maxHeap.top();
//         maxHeap.pop();
//         int topSecondCount = topSecond->count;
//         char topSecondElement = topSecond->data;

//         // 5. Pehle mein se 2 char daldo ans mein
//         if (topFirstCount >= 2)
//         {
//             ans += topFirstElement;
//             ans += topFirstElement;

//             topFirstCount -= 2;
//         }
//         else
//         {
//             // topfirstCount -> one hoga
//             ans += topFirstElement;
//             topFirstCount--;
//         }

//         // 6. Dusre Element mein se 2 char daldo ans mein
//         if (topSecondCount >= 2 && topSecondCount >= topFirstCount)
//         {
//             ans += topSecondElement;
//             ans += topSecondElement;

//             topSecondCount -= 2;
//         }
//         else
//         {
//             // topSecondCount -> one hoga
//             ans += topSecondElement;
//             topSecondCount--;
//         }

//         // 7. First and Second ko vapis se maxHeap mein push krdo
//         if (topFirstCount > 0)
//         {
//             maxHeap.push(topFirst);
//         }
//         if (topSecondCount > 0)
//         {
//             maxHeap.push(topSecond);
//         }
//     }
//     if (maxHeap.size() == 1)
//     {
//         Node *temp = maxHeap.top();
//         maxHeap.pop();

//         if (temp->count >= 2)
//         {
//             ans += temp->data;
//             ans += temp->data;

//             temp->count -= 2;
//         }
//         else
//         {
//             // topfirstCount -> one hoga
//             ans += temp->data;
//             temp->count--;
//         }
//     }
//     return ans;
// }

// int main()
// {
//     int a = 1;
//     int b = 1;
//     int c = 7;
//     cout << longestDiverseString(a, b, c);
//     return 0;
// }

#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

class Node
{
public:
    char data;
    int count;

    Node(char data, int count)
    {
        this->data = data;
        this->count = count;
    }
};

class compare
{
public:
    bool operator()(Node *a, Node *b)
    {
        return a->count < b->count;
    }
};

string longestDiverseString(int a, int b, int c)
{
    // 1. Make prioirty Queue
    priority_queue<Node *, vector<Node *>, compare> maxHeap;

    // 2. Push a b c into heap
    if (a > 0)
    {
        Node *temp = new Node('a', a);
        maxHeap.push(temp);
    }
    if (b > 0)
    {
        Node *temp = new Node('b', b);
        maxHeap.push(temp);
    }
    if (c > 0)
    {
        Node *temp = new Node('c', c);
        maxHeap.push(temp);
    }

    string ans = "";

    // 3. Extract and push into ans;
    while (maxHeap.size() > 1)
    {
        // 4. Top ke 2 elements extract krlo or daldo
        Node *topFirst = maxHeap.top();
        char topFirstElement = topFirst->data;
        int topFirstCount = topFirst->count;
        maxHeap.pop();

        Node *topSecond = maxHeap.top();
        char topSecondElement = topSecond->data;
        int topSecondCount = topSecond->count;
        maxHeap.pop();

        // 5. Insert krdo first element ans string mein
        if (topFirstCount >= 2)
        {
            // 6. Insert two times
            ans += topFirstElement;
            ans += topFirstElement;

            topFirstCount--;
            topFirstCount--;
        }
        else
        {
            // 7. Insert only once
            ans += topFirstElement;
            topFirstCount--;
        }

        // 8. Insert krdo second element ans string mein
        if (topSecondCount >= 2 && topSecondCount >= topFirstCount)
        {
            // 9. Insert two times
            ans += topSecondElement;
            ans += topSecondElement;

            topSecondCount--;
            topSecondCount--;
        }
        else
        {
            // 10. Insert only once
            ans += topSecondElement;
            topSecondCount--;
        }

        // 11. Push Back into maxHeap
        if (topFirstCount > 0)
        {
            maxHeap.push(topFirst);
        }
        if (topSecondCount > 0)
        {
            maxHeap.push(topSecond);
        }
    }

    while (maxHeap.size() == 1)
    {
        Node *temp = maxHeap.top();
        maxHeap.pop();

        if (temp->count >= 2)
        {
            ans += temp->data;
            ans += temp->data;

            temp->count--;
            temp->count--;
        }
        else
        {
            ans += temp->data;
            temp->count--;
        }
    }
    return ans;
}

int main()
{
    int a = 1;
    int b = 1;
    int c = 7;
    cout << longestDiverseString(a, b, c);
    return 0;
}
