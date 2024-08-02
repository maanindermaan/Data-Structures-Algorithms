#include<iostream>
using namespace std;
int main(){

return 0;
}

struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data=val;
        next=NULL;
    }
};

class Solution{
public:
    Node* findIntersection(Node* head1, Node* head2)
    {
        // 1. Unordered Map create
        unordered_map<int , int> map; //{root->data , occurrence}
        
        // 2. because of ans order
        Node* curr = head2;
        
        // 3. Hash L2
        while(curr){
            map[curr->data]++;
            curr = curr->next;
        }
        
        // 4. Create a intersected list
        Node* IL = NULL;
        Node* it = nullptr; // Initialize to nullptr instead of 0
        
        curr = head1;
        
        while(curr){
            if(map.find(curr->data) != map.end()){
                // 5. Node value found
                // 6. When Intersection List is empty
                if(!IL){
                    IL = curr;
                    it = IL;
                }
                else{
                    // When list is not empty and occurrence is > 0, not 1
                    if(map[curr->data] > 0){
                        it->next = curr;
                        it = it->next;
                        // Decrement the occurrence
                        map[curr->data]--;
                    }
                }
            }
            curr = curr->next;
        }
        
        if (it) {
            it->next = nullptr; // Set the next of the last node to nullptr
        }
        
        return IL;
    }
};
