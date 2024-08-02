#include<iostream>
#include<vector>
using namespace std;
int main(){

return 0;
}

// 1. BRUTE FORCE 
double minimiseMaxDistance(vector<int> &arr, int k){
	vector<int>howMany(arr.size()-1 , 0);
	for(int gasStations=1 ; gasStations<=k ; gasStations++){
		long double maxSection = -1;
		int maxInd = -1;		
		for(int i=0 ; i<arr.size()-1 ; i++){
			long double diff = arr[i+1] - arr[i];
			long double sectionLength = diff / (long double)(howMany[i] + 1);

			if(maxSection < sectionLength){
				maxSection = sectionLength;
				maxInd = i;
			}
		}
		howMany[maxInd]++;
	}
	long double maxAns = -1;
	for(int i=0 ; i<arr.size()-1 ; i++){
		long double diff = arr[i+1] - arr[i];
		long double sectionLength = diff / (long double)(howMany[i] + 1);
		maxAns = max(maxAns , sectionLength);
	}
	return maxAns;
}



// 2. Prioirty Queue Method 
// #include<bits/stdc++.h>
// #include<priority_queue>
// double minimiseMaxDistance(vector<int> &arr, int k){
// 	vector<int>howMany(arr.size()-1 , 0);
// 	priority_queue<pair<long double , int>>pq;
// 	// insert all the sections in pq
// 	for(int i=0 ; i<arr.size()-1 ; i++){
// 		pq.push({arr[i+1] - arr[i] , i});
// 	}
// 	for(int gasStations=1 ; gasStations<=k ; gasStations++){
// 		// int maxSection = pq.top().first;
// 		// int maxIndex = pq.top().second;
// 		auto top = pq.top();
// 		pq.pop();
// 		int secInd = top.second;
// 		howMany[secInd]++;
// 		long double diff = (arr[secInd+1] - arr[secInd]);
// 		long double newSectionLength = diff /  (long double) (howMany[secInd]+1);
// 		pq.push({newSectionLength , secInd});
// 	}
// 	return pq.top().first;
// }


// 3. Binary Search Method
int numberOfGasStationsRequired(vector<int>&arr , long double mid){
	int cnt = 0;
	for(int i=1 ; i<arr.size() ; i++){
		int numberInBetween = ((arr[i] - arr[i-1])/ mid);
		// if exact division
		if(((arr[i] - arr[i-1])/ mid) == numberInBetween*mid){
			numberInBetween--;
		}
		cnt += numberInBetween;
	}
	return cnt;
}

double minimiseMaxDistance(vector<int> &arr, int k){
	int n = arr.size();
	long double start = 0;
	long double end = 0;
	for(int i=0 ; i<n-1 ; i++){
		end = max(end , (long double)(arr[i+1] - arr[i]));
	}
	long double diff = 1e-6; // this means 10 to power -6

	// Just becuase it is in terms of double or long double we cannot do -1 or +1 becuase that will eliminate a lot of numbers
	while(end - start > diff){
		long double mid = start + (end-start)/(2.0);
		int cnt = numberOfGasStationsRequired(arr , mid);
		if(cnt > k){
			// too low not possible eliminate left half
			start = mid;
		}
		else{
			// eliminate right half
			end = mid;
		}
	}
	return end;
}
