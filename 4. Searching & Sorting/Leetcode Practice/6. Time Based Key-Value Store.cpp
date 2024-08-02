#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;
int main(){

return 0;
}

class TimeMap {
public:
    unordered_map<string , vector<pair<int , string>>>mp;

    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        // push the {key , {timestamp , value}}
        mp[key].push_back({timestamp , value});
    }
    
    string get(string key, int timestamp) {
        // here we extract from the mp and disply the answer

        // nahi mila toh empty return krdo
        // end tak chale gye or nahi mila
        if(mp.find(key) == mp.end()){
            return "";
        }
        int start = 0;
        int end = mp[key].size()-1;

        // bada toh allowed hi nahi hai bhaii ki "foo bar 4" set tha or tumne "foo 3" ko get kia toh kuch ni milega agar "foo 5" kia toh "-> bar" miljega becuase just chota return krna hai
        if(mp[key][0].first > timestamp){ // {key , {timestap , value}} -> here we talked about 0th col of {timestamp , value} and if here's timestamp > orignal timestamp that means it violated our condition so return empty of it
            return "";
        }

        string ans = "";

        while(start <= end){
            int mid = start + (end-start)/2;
            if(mp[key][mid].first == timestamp){
                return mp[key][mid].second;
            }
            else if(mp[key][mid].first < timestamp){
                // ans store and move to right
                ans = mp[key][mid].second;
                start = mid+1;
            }
            else{
                // move to left
                end = mid-1;
            }
        }
        return ans;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */