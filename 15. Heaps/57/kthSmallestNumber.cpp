#include <iostream>
#include<queue>
using namespace std;

int getKthSmallestElement(int arr[], int n, int k ) {
        //create max heap (Descending Order In QUEUE)
        priority_queue<int> pq;
        //insert inital k elements of array 
        for(int i=0; i<k; i++) {
                pq.push(arr[i]);
        }
        //for remaining elements, push only if they are less than top
        for(int i =k; i<n; i++) {
                int element = arr[i];
                if(element < pq.top()) {
                        pq.pop();
                        pq.push(element);
                }
        }
        int ans = pq.top();
        return ans;

}

// Using min heap
int getKthSmallestElement2(int arr[], int n, int k ) {
        //create min heap
        priority_queue<int , vector<int> , greater<int>> pq;
        //insert n elements of array 
        for(int i=0; i<n; i++) {
                pq.push(arr[i]);
        }

        // Now pop k times to get kth smallest number
        int ans = 0;
        while(k--){
                ans = pq.top();
                pq.pop();
        }

        return ans;
}


int main() {
        int arr[] = {10,5,20,4,15};
        int n = 5;
        int k = 2;
        int ans = getKthSmallestElement(arr, n, k );
        cout << "Ans is: " << ans << endl;
        return 0;
}