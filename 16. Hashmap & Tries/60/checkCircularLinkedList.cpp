#include<iostream>
#include<unordered_map>
using namespace std;

class Node{

};

bool isCircular(Node* head){
    unordered_map<Node* , bool> visited;
    Node* temp = head;

    while(temp!= NULL){
        if(visited.find(temp) != visited.end()){
            // Milgya
            return true;
        }
        else{
            // Nahi mila
            visited[temp] = true;
        }
    }
    return false;
}

int main(){
    
return 0;
}