#include<iostream>
using namespace std;
int main(){
    
return 0;
}
int upperBound(vector<int> &arr, int x, int n){
	int start = 0;
	int end = n-1;
	int ans = n;

	while(start <= end){
		int mid = start + (end-start)/2;
		if(arr[mid] > x){
			ans = mid;
			// search in left
			end = mid-1;
		}
		else{
			// search in right
			start = mid+1;
		}
	}
	return ans;
}

