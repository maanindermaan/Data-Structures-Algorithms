#include<iostream>
#include<vector>
using namespace std;
int main(){

return 0;
}

// 1.
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // Brute Force Merge and find mid 
        // 1. Merging 
        int i=0;
        int j=0; 
        int k=0;
        int n1 = nums1.size();
        int n2 = nums2.size();
        int n = n1+n2;
        vector<int>arr(n , -1);

        while(i<n1 && j<n2){
            if(nums1[i] <= nums2[j]){
                arr[k] = nums1[i];
                i++;
                k++;
            } 
            else{
                arr[k] = nums2[j];
                j++;
                k++;
            }
        }
        while(i<n1){
            arr[k] = nums1[i];
            i++;
            k++;
        }
        while(j<n2){
            arr[k] = nums2[j];
            j++;
            k++;
        }

        // 2. Now finding and inserting mid
        if(n % 2 == 1){
            // odd
            return arr[n/2];
        }
        else{
            return ((arr[n/2] + arr[n/2 - 1])/2.0); // corrected index and added ".0" to ensure floating point division
        }
    }
};




// 2. Optimised Approach
// Striver's
class Solution {
public:
    double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
        // even case
        int element1 = -1;
        int element2 = -1;
        int cnt = 0;
        int i=0;
        int j=0;
        int n1 = nums1.size(); 
        int n2 = nums2.size(); 
        int n = n1+n2;
        int ind2 = n/2;
        int ind1 = ind2-1;
        // even case
        while(i<n1 && j<n2){
            if(nums1[i] < nums2[j]){
                if(cnt == ind1){
                    element1 = nums1[i];
                }
                else if(cnt == ind2){
                    element2 = nums1[i];
                }
                i++;
                cnt++;
            }
            else{
                if(cnt == ind1){
                    element1 = nums2[j];
                }
                else if(cnt == ind2){
                    element2 = nums2[j];
                }
                cnt++;
                j++;
            }
        }
        while(i<n1){
            if(cnt == ind1){
                element1 = nums1[i];
            }
            else if(cnt == ind2){
                element2 = nums1[i];
            }
            i++;
            cnt++;
        }
        while(j < n2){
            if(cnt == ind1){
                element1 = nums2[j];
            }
            else if(cnt == ind2){
                element2 = nums2[j];
            }
            j++;
            cnt++;
        }
        if(n%2 == 0){
            return (element1 + element2)/2.0;
        }
        else{
            return element2;
        }
    }
};






// 3. Optimised Approach MINES
class Solution {
public:
    double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
        // even case
        int element1 = -1;
        int element2 = -1;
        int cnt = 0;
        int i=0;
        int j=0;
        int n1 = nums1.size(); 
        int n2 = nums2.size(); 
        int n = n1+n2;
        int ind1 = n/2;
        int ind2 = (n/2)-1;
        // even case
        while(i<n1 && j<n2){
            if(nums1[i] < nums2[j]){
                if(cnt == ind1){
                    element1 = nums1[i++];
                }
                else if(cnt == ind2){
                    element2 = nums1[i++];
                }
                else{
                    i++;
                }
            }
            else{
                if(cnt == ind1){
                    element1 = nums2[j++];
                }
                else if(cnt == ind2){
                    element2 = nums2[j++];
                }
                else{
                    j++;
                }
            }
            cnt++;
        }
        while(i<n1){
            if(cnt == ind1){
                element1 = nums1[i++];
            }
            else if(cnt == ind2){
                element2 = nums1[i++];
            }
            else{
                i++;
            }
            cnt++;
        }
        while(j < n2){
            if(cnt == ind1){
                element1 = nums2[j++];
            }
            else if(cnt == ind2){
                element2 = nums2[j++];
            }
            else{
                j++;
            }
            cnt++;
        }
        if(n%2 == 0){
            return (element1 + element2)/2.0;
        }
        else{
            return element1;
        }
    }
};










// 4. Binary Search Approach Mine (Some errors)
class Solution {
public:
    double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        int n = n1 + n2;
        int l1, l2, r1, r2 = -1;
        int start = 0;
        int end = n / 2;
        int left_shift = -1;

        if(n1 == 0 && n2 == 0){
            return 0.0;
        }

        if(n2 == 0){
            if( n1 % 2 == 0){
                // even case
                return (nums1[n1/2] + nums1[(n1/2) - 1]) / 2.0;
            }
            else{
                return nums1[n1/2];
            }
        }
        
        if(n1 == 0){
            if( n2 % 2 == 0){
                // even case
                return (nums2[n2/2] + nums2[(n2/2) - 1]) / 2.0;
            }
            else{
                return nums2[n2/2];
            }
        }

        while (start <= end) {
            int mid = start + (end - start) / 2;
            // cout<<"mid->"<<mid<<endl;
            // l1 = nums1[mid-1];
            // cout<<"l1->"<<l1<<endl;
            // l2 = nums2[(n/2) - (mid+1)];
            // cout<<"l2->"<<l2<<endl;
            // r1 = nums1[mid];
            // cout<<"r1->"<<r1<<endl;
            // r2 = nums2[(n/2) - mid];
            // cout<<"r2->"<<r2<<endl;
            
            l1 = (mid > 0) ? nums1[mid - 1] : INT_MIN;
            l2 = ((n / 2) - (mid + 1) >= 0) ? nums2[(n / 2) - (mid + 1)] : INT_MIN;
            r1 = (mid < n1) ? nums1[mid] : INT_MAX;
            r2 = ((n / 2) - mid < n2) ? nums2[(n / 2) - mid] : INT_MAX;
            
            
            // cout<<"mid->"<<mid<<endl;
            // cout<<"l1->"<<l1<<endl;
            // cout<<"l2->"<<l2<<endl;
            // cout<<"r1->"<<r1<<endl;
            // cout<<"r2->"<<r2<<endl;

            if (l1 <= r2 && l2 <= r1) {
                // match 
                left_shift = mid;
                // cout<<"MATHC"<<endl;
                break;
                
            }
            else if (l1 > r2) {
                cout<<"THIS ONE"<<endl;
                // right side go to left
                end = mid - 1;
            }
            else if (l2 > r1) {
                cout<<"THIS TWO"<<endl;
                // left side go to right
                start = mid + 1;
            }
        }
        double median = 0.0;

        // Calculate median here
        if(n%2 == 0){
            median = (max(l1 , l2) + min(r1 , r2))/2.0;
        }
        else{
            median = min(r1 , r2);
        }

        return median;
    }
};







// 5. Binary Search Approach STRIVER'S
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        int n = n1+n2;

        // hmesha n1 chodta rhega isse humne n1 ke correspondingly operations kare haii
        // This condition essentially checks if nums1 is longer than nums2. If it is, it swaps the arrays and calls findMedianSortedArrays again.
        // In summary, the condition if (n1 > n2) and the subsequent array swap ensure that the findMedianSortedArrays function can effectively handle cases where nums1 is longer than nums2, allowing for a simpler and more consistent implementation.

        if(n1>n2){
            return findMedianSortedArrays(nums2 , nums1);
        }

        int start = 0;
        int end = n1;
        int left = (n1+n2+1)/2;

        while(start <= end){
            int mid1 = start + (end-start)/2;
            int mid2 = left - mid1;
            int l1 = INT_MIN , l2 = INT_MIN;
            int r1 = INT_MAX , r2 = INT_MAX;

            if(mid1 < n1){
                r1 = nums1[mid1];
            }
            if(mid2 < n2){
                r2 = nums2[mid2];
            }
            if(mid1 - 1 >= 0){
                l1 = nums1[mid1-1];
            }
            if(mid2 - 1 >= 0){
                l2 = nums2[mid2-1];
            }

            // Match 
            if(l1<=r2 && l2 <= r1){
                // odd case
                if(n%2 == 1){
                    return max(l1 , l2);
                }
                // even case
                else{
                    return ((double)(max(l1 , l2) + min(r1 , r2)))/2.0;
                }
            }

            // Right part go to left
            else if(l1 > r2){
                end = mid1-1;
            }
            // left part goto right
            else{
                start = mid1+1;
            }
        }
        return 0.0;
    }
};