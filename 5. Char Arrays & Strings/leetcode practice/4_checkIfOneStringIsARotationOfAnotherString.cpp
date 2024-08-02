#include<iostream>
using namespace std;
int main(){

return 0;
}

// Method 1 
class Solution {
public:

    int countSubstringOccurrences(const std::string& p, const std::string& substr) {
        int count = 0;
        size_t pos = 0;

        while ((pos = p.find(substr, pos)) != std::string::npos) {
            count++;
            pos += substr.length();
        }

        return count;
    }


    bool rotateString(string p, string q) {
        if(p.size() != q.size()){
            return 0;
        }
        
        // Loop 1 
        // finding correct value of i
        int k=1;
        while(countSubstringOccurrences(p , q.substr(0 , k)) != 1){
            k++;
        }
        int i = p.find(q.substr(0,k));
        int j = 0;

        while (i < p.size() && j < q.size()) {
            if (p[i] != q[j]) {
                return 0;
            } else {
                i++;
                j++;
            }
        }

        // Loop 2 
        i = 0;
        j = j;

        while (i < p.size() && j < q.size()) {
            if (p[i] != q[j]) {
                return 0;
            } else {
                i++;
                j++;
            }
        }

        return 1;
    }
};



// Method -2  -> TC(O(N^2)) SC(O(N))
int isCyclicRotation(string &p, string &q) 
{
    if(p.size() != q.size()){
        return 0;
    }
    string ans = p+p;

    if(ans.find(q) != string::npos){
        return 1;
    }
    return 0;
}




// Method 3 
