// Find Missing elemets from array with duplicates
#include<iostream>
using namespace std;


void missingElements(vector<int>&v){
    for(int i=0 ; i<v.size() ; i++){
        int index = abs(v[i]);

        // marking Visited
        if(v[index-1]>0){
            v[index-1] *=-1;
        }
    }

    for(int i=0 ; i<v.size() ; i++){
        if(v[i]>0){
            cout<<"Missing element is : "<<i+1;
        }
    }
}

int main(){
    vector<int>v{1,3,5,3,4};

    for(int i=0 ; i<v.size() ; i++){
    cout<<v[i]<<" ";
    }
    cout<<endl;

    missingElements(v);

    for(int i=0 ; i<v.size() ; i++){
    cout<<v[i]<<" ";
    }

return 0;
}





// Missing Element -> METHOD -2
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;


int missing(vector<int>&v){
    vector<int>arr(v.size(),-1);
    int ans = 0;
    cout<<endl;
    cout<<endl;
    for(int i=0 ; i<v.size() ; i++){
        int index = v[i]-1;
        arr[index] = index;
    }
    for(int i=0 ; i<arr.size() ; i++){
        if(arr[i] == -1){
            ans = i+1;
        }
    }
    return ans;
}



int main(){

vector<int>v{1,2,3,4,5,6,7,8,9,10,11,13};

for(int i=0 ; i<v.size() ; i++){
    cout<<v[i]<<" ";
}
cout<<endl;

int ans = missing(v); 
cout<<"Missing Element is : "<<ans;

return 0;
}