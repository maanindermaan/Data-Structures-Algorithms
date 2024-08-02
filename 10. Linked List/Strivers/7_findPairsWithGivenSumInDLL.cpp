// Approach 1 recursion but TLE
#include<iostream>
#include<vector>
using namespace std;
int main(){

return 0;
}

class Node
{
public:
    int data;
    Node *next, *prev;
    Node(int val) : data(val), next(NULL), prev(NULL)
    {
    }
};

class Solution
{
public:
    void recursiveHelper(Node* current, Node* head, int target, vector<pair<int, int>>& ans, pair<int, int>& p) {
        // base case
        if (current == NULL) {
            return;
        }
        
        // handling linked list traversal
        Node* temp = current->next;
        
        while (temp != NULL) {
            p.first = current->data;
            p.second = temp->data;
            
            if (p.first + p.second == target) {
                ans.push_back(p);
            }
            
            temp = temp->next;
        }
        
        // Recursive call to the next node
        recursiveHelper(current->next, head, target, ans, p);
    }
    
    vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target)
    {
        vector<pair<int,int>>ans;
        pair<int,int>initial;
        initial.first = -1;
        initial.second = -1;
        recursiveHelper(head,head , target , ans , initial);
        return ans;
    }
};







// Approach 2 
class Solution
{
public:
    vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target)
    {
        vector<pair<int,int>>ans;
        Node *temp1 = head;
        
        while(temp1 != NULL){
            Node* temp2 = temp1->next;
            while(temp2!=NULL && (temp1->data + temp2->data <= target)){
                if(temp1->data + temp2->data == target){
                    ans.push_back({temp1->data , temp2->data});
                }
                temp2 = temp2->next;
            }
            temp1 = temp1->next;
        }
        return ans;
    }
};








// Approach 3 Best Approach
class Solution
{
public:
    Node* findTail(Node* head) {
        Node* tail = head;
        while(tail->next != NULL) tail = tail->next;
        return tail;
    }

    vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target)
    {
        vector<pair<int,int>>ans;
        Node* left = head;
        Node* right = findTail(head);
        
        while(left->data < right->data){
            if(left->data + right->data == target){
                ans.push_back({left->data , right->data});
                left = left->next;
                right = right->prev;
            }
            else if(left->data + right->data < target){
                left = left->next;
            }
            else{
                right = right->prev;
            }
        }
        return ans;
    }
};