#include<iostream>
#include<stack>
using namespace std;
int main(){

return 0;
}

void insertSorted(stack<int>& s , int temp){
	// ya toh khali hoga stack ya fir toppe usse chota hoga tabhi dalunga vrna jo pdada hai use nikalna padega
	if(s.empty() || s.top() <= temp){
		s.push(temp);
		return;
	}

	// ab agar bada hai toh use nikalo bc
	int top = s.top();
	s.pop();
	insertSorted(s , temp);

	// nikaldia tha uper toh daldo ab
	s.push(top);
}

// yeah wala function elements ko nikalega ek ek krke or ek alag function ko dedega taaki voh insert krsake 
void sortStackRecursive(stack<int>&s){
	// base case
	if(s.empty()){
		return;
	}

	int temp = s.top();
	s.pop();

	sortStackRecursive(s);

	insertSorted(s , temp);
}

void reverseStack(stack<int> &s) {
    sortStackRecursive(s);
}