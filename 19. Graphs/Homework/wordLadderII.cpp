#include<iostream>
#include<queue>
#include<unordered_set>
using namespace std;
int main(){

return 0;
}

class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        // 1. for giving the answer 
        vector<vector<string>>ans;
        
        // 2. create a queue
        queue<pair<vector<string> , int>>q; // {sequence , count/level}

        // 3. Create a unordered set
        unordered_set<string>st(wordList.begin() , wordList.end());

        // 4. Insert initial element to queue
        q.push({{beginWord} , 1});

        // 5. erase karna hai set/dictionary se word level change par
        int prevLevel = -1;
        vector<string>toBeRemoved;

        // 6. apply bfs logic
        while(!q.empty()){
            // 7. Extracting top element
            auto fnode = q.front();
            q.pop();

            auto currSeq = fnode.first;
            auto currString = currSeq[currSeq.size()-1]; // last wali
            auto currLevel = fnode.second;

            // 8. Level change hone par
            if(currLevel != prevLevel){ 
                // 9. to saare remove krdon
                for(auto s:toBeRemoved){
                    st.erase(s);
                }
                toBeRemoved.clear();
                prevLevel = currLevel;
            }

            // 10. checking this with end word
            if(currString == endWord){
                ans.push_back(currSeq);
            }

            // 11. Now checking for each char of currString
            for(int i = 0 ; i < currString.size() ; i++){
                char origChar = currString[i];

                // 12. now giving 25 options to this i
                for(char ch = 'a' ; ch <= 'z' ; ch++){
                    currString[i] = ch;

                    // 13. Comparing this new string with set
                    if(st.find(currString) != st.end()){

                        auto temp = currSeq;
                        temp.push_back(currString);


                        // 14. If found insert to queue
                        q.push({temp , currLevel+1});

                        toBeRemoved.push_back(currString);
                    }
                }
                // 15. If not matched replace with orignal char
                currString[i] = origChar;
            }
        }
        return ans;
    }
};