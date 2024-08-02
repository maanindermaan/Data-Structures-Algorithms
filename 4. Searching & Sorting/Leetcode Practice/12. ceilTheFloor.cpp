#include<iostream>
#include<vector>
using namespace std;
int main(){
    
return 0;
}
pair<int, int> getFloorAndCeil(vector<int> &arr, int n, int x) {
	int start = 0;
	int end = n-1;
	int floor = -1;
	int ceil = -1;

	// for floor :-
	while(start <= end){
		int mid = start + (end-start)/2;
		if(arr[mid] <= x){
			// store and right search
			floor = arr[mid];
			start = mid+1;
		}
		else{
			// left search
			end = mid-1;
		}
	}

	start = 0;
	end = n-1;

	// for ceil :-
	while(start <= end){
		int mid = start + (end-start)/2;
		if(arr[mid] >= x){
			// store and left search
			ceil = arr[mid];
			end = mid-1;
		}
		else{
			// right search
			start = mid+1;
		}
	}
	return {floor , ceil};
}