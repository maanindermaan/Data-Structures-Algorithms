#include<iostream>
#include<queue>
using namespace std;
int main(){
    string str = "aabc";
    int freq[26] = {0};
    queue<char>q;

    string ans = "";

    for(int i=0 ; i<str.size() ; i++){
        char ch = str[i];

        // 1. increment frequency 
        freq[ch - 'a']++; // this gives us a integer number;

        // 2. push in queue
        q.push(ch);

        // 3. Check in queue and give first non repeating element having count< 1;
        while(!q.empty()){
            if(freq[q.front() - 'a'] > 1){ // repeating character
                q.pop();
            }
            else{
                ans.push_back(q.front());
                break; // ans mil chuka hai to baaki ku check karna 
            }
        }

        if(q.empty()){
            ans.push_back('#');
        }
        
    }

    cout<<ans<<" ";
return 0;
}





// Apporach 2
#include<iostream>
#include<queue>
using namespace std;
char firstNonRepeatingCharacter(string str) {

  unordered_map<char , int>map;
  queue<char>q;
  char ans='\0';

  for(int i=0 ; i<str.size() ; i++){
      char ch = str[i];

      if(map.empty()){
          map[ch]++;
      }

      if(q.empty()){
          q.push(ch);
      }
      else{
        //   check if it is present in map or not
        if(map.find(ch) == map.end()){
            q.push(ch);
        }
      }

      if(i != 0){
        map[ch]++;
      }
  }

  while(!q.empty()){
      char ch = q.front();
      q.pop();

      if(map[ch] == 1){
          return ch;
      }
  }
  return ans;

}



// 3. Correct Approach 
#include<iostream>
#include<queue>
using namespace std;
char firstNonRepeatingCharacter(string str) {

  unordered_map<char , int>map;
  queue<char>q;
  char ans = '\0';

  for(int i=0 ; i<str.size() ; i++){
    char ch = str[i];

    map[ch]++;

    q.push(ch);
  }

  while(!q.empty()){
    if(map[q.front()] == 1){
      return q.front();
    }
    else{
      q.pop();
    }
  }
  return ans;
}



// Approach 4
#include<iostream>
#include<queue>
using namespace std;
char firstNonRepeatingCharacter(string str) {
    unordered_map<char, int> map;
    queue<char> q;
    
    for (int i = 0; i < str.size(); i++) {
        char ch = str[i];
        map[ch]++;
        q.push(ch);

        // Remove all characters from the front of the queue which have count > 1
        while (!q.empty() && map[q.front()] > 1) {
            q.pop();
        }
    }
    
    // Return the first non-repeating character
    if (!q.empty()) {
        return q.front();
    }
    
    // If no non-repeating character is found, return a null character
    return '\0';
}
