#include<iostream>
#include<vector>
#include<stack>
using namespace std;
int main(){

return 0;
}

// 1. Brute Force Solution
vector<int> recursive(stack<int>& s , vector<int>& arr){
	// base case
	if(s.empty()){
		return arr;
	}

	int top = s.top();
	s.pop();
	arr.push_back(top);

	return recursive(s , arr);
}

stack<int> sortStack(stack<int> &s)
{
	vector<int>arr;
	arr = recursive(s , arr);

	sort(arr.begin() , arr.end());

	for(int i=0 ; i <arr.size() ; i++){
		s.push(arr[i]);
	}
	return s;
}