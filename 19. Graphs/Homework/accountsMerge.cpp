#include<iostream>
#include<set>
using namespace std;
int main(){

return 0;
}
class Solution {
public:

    int findParent(vector<int>&parent , int node){
	    if(parent[node] == node){
	        return node;
	    }
	    return parent[node] = findParent(parent , parent[node]); // path compression
	}
	
	void unionSet(int u , int v , vector<int>&parent , vector<int>&rank){
	    u = findParent(parent , u);
	    v = findParent(parent , v);
	    
	   // u ka parent u mien h stor krdiya
	    if(rank[u] < rank[v]){
	       // u chota hai 
	       parent[u] = v;
	       rank[v]++;
	    }
	    else{
	        parent[u] = v;
	        rank[u]++;
	    }
	}

    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        // 1. making parent array
        vector<int>parent(n);

        // 2. making a rank array
        vector<int>rank(n , 0);

        // 3. saari nodes ke parent vo khud hi hote hai
        for(int u = 0 ; u < n ; u++){
            parent[u] = u;
        }

        // 4. Making an unordered map
        unordered_map<string , int>mp;
        for(int i = 0 ; i<n ; i++){
            // 5. Ek account utha lo
            auto account = accounts[i];

            // 6. Ab har account ka jo start index hai vha toh names hai next position se mail ID start hai
            for(int j=1 ; j<account.size() ; j++){
                // 7. sabse pehle mail ID nikalle
                string&mail = account[j];

                // 8. Kya meri mail pehle se map mein mojood hai?
                auto it = mp.find(mail);

                // 9. agar pehle se map mein nahi hai toh push krdo use map mein
                // e.g. agar j1 map mein nahi tha jo j1 map mein daldo or btado ki kis account ya node se belong karta hai
                if(it == mp.end()){
                    mp[mail] = i;
                }
                // 10. Aagar pehlse map mein hai toh fir
                // e.g. ab j1 pehle se map mein hai toh humne uski entry nahi daali, ab j1 pehlse se map mein hai or j1 kehrha hai ki mai toh 0 node se belong krta hu or naye j1 kehrhe hai hum toh 1 account se belong krta hu, to iska matlab kyunki dono email ID same hai, so this signifies that 0 and 1 are siingle component only
                else{
                    // 11. Toh maine iss case mein union krdiya
                    unionSet(i , it->second , parent , rank);
                }
            }
        }

        // 12. Making a unordered map of pre Ans
        // mp ko iterate krke preAns banega
        unordered_map<int , set<string>>preAns;
        for(auto it:mp){
            auto accountNo = it.second;
            auto mail = it.first;
            // 13. Ab humne uper wali lino se J1 read krliya mail wale variable mein or 0 read krliya account number mein
            // 14. Ab accountNo change bhi ho sakta hai becuase hum har baar parent wala accountNo lenge
            accountNo = findParent(parent , accountNo); // e.g. 1 ka parent in (mp) 0 banjayega or hum 0 ke corresponding entry create krenge
            preAns[accountNo].insert(mail);
        }

        // 15. Ab preAns ko use krke finalAns bana dena hai aapko
        vector<vector<string>>ans;
        for(auto it:preAns){
            // 16. preAns ka first account number dega 
            auto accountNo = it.first;
            // 17. Or iska second deta hai set of strings(saari email IDs)
            auto st = it.second;
            // 18. Sabse pehle name push krna hai, name ke liye uss accountNo ke corresponding jo accounts naam ka array hao uska first element(index) will give name
            vector<string>v;
            v.push_back(accounts[accountNo][0]);

            // 19. Ab name ke baad saari EMAIL IDs Push krdo jo ki set mein padi hai , so iterate over the set and do the follwoing
            for(auto mail : st){
                v.push_back(mail);
            }
            ans.push_back(v);
        }
        return ans;
    }
};
