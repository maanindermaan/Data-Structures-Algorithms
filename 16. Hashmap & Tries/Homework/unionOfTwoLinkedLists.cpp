#include<iostream>
#include<map>
using namespace std;
int main(){

return 0;
}

// structure of the node is as follows

struct Node
{
	int data;
	struct Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};

class Solution
{
    public:
    struct Node* makeUnion(struct Node* head1, struct Node* head2)
    {
        // 1. Create a map
        map<int,Node*> map; //{int , NODE*}
        
        // 2. LL 1 HASHED
        Node* curr = head1;
        while(curr){
            map[curr->data] = curr;
            curr = curr->next;
        }
        
        curr = head2;
        
        // 3. LL 2 HASHED
        while(curr){
            map[curr->data] = curr;
            curr = curr->next;
        }
        
        Node* UL = NULL;
        curr = 0;
        
        // 4. iterate over map and make FINAL UL
        for(auto it= map.begin() ; it!= map.end() ; it++){
            if(!UL){
                UL = it->second;
                curr = UL;
            }
            else{
                curr->next = it->second;
                curr = curr->next;
            }
        }
        curr->next = NULL;
        return UL;
    }
};