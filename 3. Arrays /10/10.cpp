// ARRAY-II
#include <iostream>
#include <vector>
using namespace std;

int findUnique(vector<int> arr) {
	int ans = 0;

	for(int i=0; i<arr.size(); i++) {
		ans = ans ^ arr[i];
	}

	return ans;
}

bool find(vector<int>arr , int target , int size){
	for(int i=0 ; i<size ; i++){
		if(arr[i] == target){
			return true;
		}
	}
	return false;
}

void printArray(vector<int> arr) {
	for(auto i:arr) {
		cout << i << " ";
	}
	cout << endl;
}
int main() {
	// //create vector
	// vector<int> arr;
	
	// // int ans = (sizeof(arr)/sizeof(int)) ;
	// // cout << ans << endl;
	
	// cout << arr.size() << endl;
	// cout << arr.capacity() << endl;

	// //insert
	// arr.push_back(5);
	// arr.push_back(6);

	// //print
	// for(int i=0; i<arr.size(); i++) {
	// 	cout << arr[i] << " ";
	// }
	// cout << endl;

	// //remove / delete
	// arr.pop_back();

	// //print
	// for(int i=0; i<arr.size(); i++) {
	// 	cout << arr[i] << " ";
	// }
	// cout << endl;

	// int n ;
	// cout<<"Enter the value of n " << endl;

	// cin >> n;
	
	// vector<int> brr(n, -101);
	// cout << "Size of b " << brr.size() << endl;
	// cout << "Capacity of b " << brr.capacity() << endl;
	

	// for(int i=0; i<brr.size(); i++) {
	// 	cout << brr[i] << " ";
	// }
	// cout << endl;

	// cout << "Printing crr" << endl;
	// vector<int> crr{10,20,30,50};

	// for(int i=0; i<crr.size(); i++) {
	// 	cout << crr[i] << " ";
	// }
	// cout << endl;

	// cout << "Vector crr is Empty or not " <<crr.empty() << endl;

	// vector<int> drr;
	// cout << "Vector drr is empty or not " << drr.empty() << endl;


	// UNique Element

	// int n;
	// cout << "Enter the size of array " << endl;
	// cin >> n; 


	// vector<int> arr(n);
	// cout << "Enter the elements " << endl;
	// //taking input
	// for(int i=0; i<arr.size(); i++) {
	// 	cin >> arr[i];
	// }

	// int uniqueElement = findUnique(arr);

	// cout << "Unique Element is  " << uniqueElement << endl;


	//UNION (without Duplicates)
	// int arr[] = {1,3,5,7,9};
	// int sizea = 5;
	// int brr[] = {2,4,6,8};
	// int sizeb = 4;

	// vector<int> ans;

	// //push all element of vector arr
	// for(int i=0; i<sizea; i++) {
	// 	ans.push_back(arr[i]);
	// }

	// //push all element of vector brr
	// for(int i=0; i<sizeb; i++) {
	// 	if(find(ans , brr[i] , ans.size()) == false){
	// 		ans.push_back(brr[i]);
	// 	}
	// }

	// //print ans
	// cout << "Printing ans array " << endl;
	// for(int i=0; i<ans.size(); i++) {
	// 	cout << ans[i] << " " ;
	// }


    // // UNION (With DUPLICATES)
    // int arr[] = {1,2,3,4,5,6,7,8};
    // int sizea = 8;
    // int brr[] = {6,7,8,9,10};
    // int sizeb = 5;

    // vector<int>ans;

	// for(int i=0 ; i<sizea ; i++){
	// 	for(int j=0 ; j<sizeb ; j++){
	// 		if(arr[i] == brr[j]){
	// 			brr[j] = INT_MAX;
	// 		}
	// 	}
	// }

	// // Pushing elments of arr into ans
    // for(int i=0 ; i<sizea ; i++){
    //     ans.push_back(arr[i]);
    // }
    // // Pushing elments of brr into ans
    // for(int i=0 ; i<sizeb ; i++){
    //     if(brr[i]!=INT_MAX){
    //     	ans.push_back(brr[i]);
    //     }
    // }
    // for(int i=0 ; i<ans.size() ; i++){
    //     cout<<ans[i]<<" ";
    // }


    // for(int i=0 ; i<sizea ; i++){
    //     for(int j=0 ; j<sizeb ; j++){
    //         if(arr[i]==brr[j]){
    //             brr[j]=INT_MIN;
    //         }
    //     }
    // }

    // // Pushing elments of arr into ans
    // for(int i=0 ; i<sizea ; i++){
    //     ans.push_back(arr[i]);
    // }
    // // Pushing elments of brr into ans
    // for(int i=0 ; i<sizeb ; i++){
    //     if(brr[i]!=INT_MIN){
    //     	ans.push_back(brr[i]);
    //     }
    // }
    // for(int i=0 ; i<ans.size() ; i++){
    //     cout<<ans[i]<<" ";
    // }


	//INTERSECTION

	// vector<int> arr{1,2,3,3,4,6,8,10};
	// vector<int> brr{3,3,4,10};

	// vector<int> ans;

	// for(int i=0 ; i<arr.size() ; i++){
	// 	for(int j=0 ; j<brr.size() ; j++){
	// 		if(arr[i] == brr[j]){
	// 			ans.push_back(arr[i]);
	// 		}
	// 	}
	// }

	// for(auto value: ans) {
	// 	cout << value << " ";
	// }

	// //outer loop on arr vector
	// for(int i=0; i<arr.size(); i++) {
		
	// 	int element = arr[i];
	// 	// for every element, run loop on brr
	// 	for(int j=0; j<brr.size(); j++) {
	// 		if(element == brr[j]) {
	// 			//mark 
	// 			brr[j] = -1;
	// 			ans.push_back(element);
	// 		}
	// 	}
	// }

	// //print ans 
	// for(auto value: ans) {
	// 	cout << value << " ";
	// }

	// cout << endl;


	//Pair Sum
	//Pair Sum
	// vector<int> arr{0 , 10,20,40,60,65, 80,80,67,78,90 , 70};
	// int sum = 80;
	// vector<pair<int , int>>ans;
	// int start = 0;
	// int end = arr.size()-1;
	// int target = 0;
	
	// sort(arr.begin() , arr.end());

	// while(start < end){
	// 	target = arr[start] + arr[end];
	// 	if(sum == target){
	// 		ans.push_back({arr[start] , arr[end]});
	// 		end--;
	// 		start++;
	// 	}
	// 	else if(sum > target){
	// 		start++;
	// 	}
	// 	else{
	// 		end--;
	// 	}
	// }

	// for(auto i : ans) {
	//     cout << "(" << i.first <<" , "<<i.second<<")"<<endl;
	// }



	// // print all pairs
	// // outer loop will traverse for each element
	// for(int i=0; i<arr.size(); i++) {
	// 	int element = arr[i] ;

	// 	//for every element, will traverse on aage wale elements
	// 	for(int j=i+1; j<arr.size(); j++) {
	// 		if(element + arr[j] == sum ){
	// 			cout << "Pair FOund " << element <<"," << arr[j] << endl;
	// 		}
	// 	}
	// }

	//TRIPLET 

	// vector<int> arr{10,20,30,40};
	// int sum = 80;

	// for(int i=0; i<arr.size(); i++) {
	// 	int element1 = arr[i];

	// 	for(int j=i+1; j<arr.size(); j++) {
	// 		int element2 = arr[j];

	// 		for(int k=j+1; k<arr.size(); k++) {
	// 			int element3 = arr[k];

	// 			if(element1 + element2 + element3 == sum) {
	// 				cout << element1 <<","<< element2 <<","<< element3 << endl;
	// 			}
	// 		}
	// 	}
	// }

    // FOURLET
    // int arr[]={10, 20, 40, 60, 70 , 80 , 90 , 100};
    // int size = 8;
    // int sum = 200;

    // // print all pairs
    // // Outer loop will traverse for each element
    // for(int i=0 ; i<size ; i++){
    //     for(int j=i+1 ; j<size ; j++){
    //         for(int k = i+2 ; k<size ; k++){
    //             for(int l = i+3 ; l<size ; l++){
    //                 if(arr[i]+arr[j]+arr[k]+arr[l]==sum){  
    //                     cout<<"("<<arr[i]<<","<<arr[j]<<","<<arr[k]<<","<<arr[l]<<")"<<endl; 
    //                 }
    //             }
    //         }
    //     }
    // }


	//sort 0 and 1s

	vector<int> arr{0,1,0,1,1,0,1,0,1,1};
	int start = 0;
	int end = arr.size() -1;
	int i = 0;

	while( i != end) {
		cout << "for i="<<i<< " start="<<start <<" end="<< end << endl;
		if(arr[i] == 0) {
			cout << "found zero" << endl;
			cout <<"before swap ";
			printArray(arr);
			
			swap(arr[start], arr[i]);
			cout <<"after  swap ";
			printArray(arr);
			start++;
			i++;
			cout << "now i="<<i<< " start="<<start <<" end="<< end << endl;
		}
		else {
			cout << "found One" << endl;
			cout <<"before swap ";
			printArray(arr);
			swap(arr[end], arr[i]);
			cout <<"after  swap ";
			printArray(arr);
			end--;
						cout << "now i="<<i<< " start="<<start <<" end="<< end << endl;

		}
	}
	
	// //print
	// for(auto val : arr) {
	// 	cout << val << " ";
	// }
	
	// 2nD Method
	// while(start != end){
	//     if(arr[start] == 0){
	//         start++;
	//     }
	//     else{
	//         swap(arr[start] , arr[end]);
	//         end--;
	//     }
	// }
	
	
	
	return 0;
}