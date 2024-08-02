#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

class Node {
public:
    char data;
    int count;

    Node(char data, int count) {
        this->data = data;
        this->count = count;
    }
};

class compare {
public:
    bool operator()(Node* a, Node* b) {
        return a->count < b->count;
    }
};

string reorganiseString(string& s) {
    // 1. create Mapping
    int freq[26] = {0};

    // 2. Attach every alphabet to numeric values i.e. count
    for (int i = 0; i < s.size(); i++) {
        char ch = s[i];
        freq[ch - 'a']++;  // convert ch to int by subtracting a. Now here a-a = 0. a is mapped to 0
    }

    // 3. Make priority Queue of maxHeap
    priority_queue<Node*, vector<Node*>, compare> maxHeap;

    // 4. Insert All elements in MaxHeap
    for (int i = 0; i < 26; i++) {
        if (freq[i] != 0) {
            Node* temp = new Node(i + 'a', freq[i]);
            maxHeap.push(temp);
        }
    }

    // 5. Extract values from Heaps
    // Heap mein hamesha 2 values honi chahiye i.e. why > 1.
    string ans = "";

    while (maxHeap.size() > 1) {
        // 6. Extracting from first Element
        Node* topFirst = maxHeap.top();
        maxHeap.pop();
        int topFirstCount = topFirst->count;
        char topFirstElement = topFirst->data;

        // 7. Extracting from Second Element
        Node* topSecond = maxHeap.top();
        maxHeap.pop();
        int topSecondCount = topSecond->count;
        char topSecondElement = topSecond->data;

        // 8. Adding both to ans string
        ans += topFirstElement;
        ans += topSecondElement;

        // 9. Reducing the frequency
        topFirstCount--;
        topSecondCount--;

        // 10. Checking if the frequency is not 0. If not 0 then put back in maxHeap
        if (topFirstCount != 0) {
            maxHeap.push(new Node(topFirstElement, topFirstCount));
        }

        if (topSecondCount != 0) {
            maxHeap.push(new Node(topSecondElement, topSecondCount));
        }
    }

    if (maxHeap.size() == 1) {
        Node* temp = maxHeap.top();
        maxHeap.pop();

        if (temp->count == 1) {
            ans += temp->data;
        } else {
            return "";
        }
    }
    return ans;
}

int main() {
    string s = "aaabccddee";
    cout << reorganiseString(s);
    return 0;
}
