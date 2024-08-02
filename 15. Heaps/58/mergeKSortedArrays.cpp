#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// 1. Class Banalo to store three elements data(jo hume dalna hai vector mein) , row(array number) and col
// (col is for index) and also make COMPRATOR because minHeap have different Complications when you use Node*
class info
{
public:
    int data;
    int row; // Konse array ke bare mein baa horhi hai
    int col; // array mein konse index ke bare mein baat horahi hai

    info(int data, int row, int col)
    {
        this->data = data;
        this->row = row;
        this->col = col;
    }
};

// Jab heap ke andar info* a type ki value aajaye or info* b type ki value aajaye toh tumhe kisko minimum manna hai kisko minimum nahi manna
class compare
{ // custom comprator
public:
    bool operator()(info *a, info *b)
    {
        return a->data > b->data;
    }
};

vector<int> mergeKSortedArrays(int arr[][4], int k, int n)
{
    priority_queue<info *, vector<info *>, compare> minHeap; // Node* data and -> I have to give my own comprator

    // 2. Har ek array ka first element insert karo
    for (int i = 0; i < k; i++)
    {
        info *temp = new info(arr[i][0], i, 0); // Pehli value matlab col will be 0 and row will be 0 too
        minHeap.push(temp);
    }

    // to store the answer
    vector<int> ans;

    // 3. Jab tak PQ empty na hojaye
    while (!minHeap.empty())
    {
        // 4. Ye four steps perform krlo
        // step 1 : top element findout krlo
        info *temp = minHeap.top();
        int topElement = temp->data;
        int topRow = temp->row;
        int topCol = temp->col;

        // step 2 : insert topElement into ans
        ans.push_back(topElement);

        // step 3 : remove that element
        minHeap.pop();

        // step 4 : add next element
        // kya uss array mein next element pada hai, agar hai toh daldo or nikal to loop dega hi
        if (topCol + 1 < n)
        {
            info *temp2 = new info(arr[topRow][topCol + 1], topRow, topCol + 1);
            minHeap.push(temp2);
        }
    }

    // 5. Last mein return krdo ans ko
    return ans;
}

int main()
{
    int arr[][4] = {{2, 4, 6, 8},
                    {1, 3, 5, 7},
                    {0, 9, 10, 11}};
    int k = 3;
    int n = 4;

    vector<int> ans = mergeKSortedArrays(arr, k, n);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}