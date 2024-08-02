#include <iostream>
#include <vector>
using namespace std;

class TrieNode
{
public:
        char data;
        TrieNode *children[26]; // for bache
        bool isTerminal;

        TrieNode(char d)
        {
                this->data = d;
                for (int i = 0; i < 26; i++)
                {
                        children[i] = NULL;
                }
                this->isTerminal = false;
        }
};

void insertWord(TrieNode *root, string word)
{
        // cout << "Inserting " << word << endl;
        // base case
        if (word.length() == 0)
        {
                root->isTerminal = true;
                return;
        }

        char ch = word[0];
        int index = ch - 'a';
        TrieNode *child;
        // present
        if (root->children[index] != NULL)
        {
                child = root->children[index];
        }
        else
        {
                // not present
                child = new TrieNode(ch);
                root->children[index] = child;
        }

        // recursion sambhal lega
        insertWord(child, word.substr(1));
}

bool searchWord(TrieNode *root, string word)
{
        // base case -> Jab Last Char Aajaye
        if (word.length() == 0)
        {
                return root->isTerminal;
        }

        char ch = word[0];
        int index = ch - 'a';
        TrieNode *child;

        // present
        if (root->children[index] != NULL)
        {
                child = root->children[index];
        }
        else
        {
                return false;
        }
        // rec call
        return searchWord(child, word.substr(1));
}











void storeSuggestions(TrieNode* curr , vector<string>&temp , string& prefix){
    // 9. Agar currNode terminal hai toh 
    if(curr->isTerminal){
        // 10. Iss case mein store karlo temp mein
        temp.push_back(prefix);
    }

    // 11. Now give choice to currenet node from a-z
    for(char ch = 'a' ; ch<='z' ; ch++){
        int index = ch-'a';

        // 12. Make next node, Hum index pe jane ki koshish krrhe hai. Like jo choice mili uspe jane ki koshish
        TrieNode* next = curr->children[index];

        // 13. Ab check kro ki kya choice mili ya nahi mili. That is kya ye next exist krta hai or not
        if(next != NULL){
            // 14. If child exits 
            prefix.push_back(ch);
            // 15. Rest cases recursion will handle
            storeSuggestions(next , temp , prefix);
            // 16. BackTracking important 
            prefix.pop_back();  // agar pop nahi karoge toh har baar previous elements bhi add hote rahenge
        }
    }
}











// Last Character tumhe pata hona chahiye, 
// or last character ke adhar par tum node find out krloge
// or node findout krke recursively tum saare ke saare uske word print krdoge 
vector<vector<string>> getSuggestions(TrieNode* root , string input){

    // 1. Make some variable or data structure
    TrieNode* prev = root;
    vector<vector<string>> output;
    string prefix = ""; // maine ye prefix sirf characters ko store krne liye banaya hai because temp is having strings

    // 2. Traverse over input string
    for(int i=0 ; i<input.size() ; i++){
        // 3. Last character nikallo
        char lastCh = input[i]; // har iteration ke baad i bad rha hai thats why character updating

        // 4. Iss character ke adhar par tum root nikalo
        int index = lastCh - 'a';

        // 5. Curr node nikal lo jo ki iss index pe hogi
        TrieNode* curr = prev->children[index];

        // 6. Kya currentNode exist karti hai ya nahi karti hai
        // if(curr->children[index] != NULL){
        if(curr == NULL){
            // Nahi karti
            break;
        }
        else{
            // 7. Mujhe mera element milgya 
            // curr node ke liyeneche se saare ke saare nodes create krkre le aao
            // temp andar mai saare suggestions store krke launga 
            vector<string> temp; 

            prefix.push_back(lastCh); // becuase pura character banane ke liye lastCh bhi dalna padega

            // 8. string create karke from storeSuggestions we are storing in temp
            storeSuggestions(curr , temp , prefix);

            // 17. Ab ye temp wala array bhar chuka hai we have to store this under outputs
            output.push_back(temp);

            // 18. Previous ko age badado
            prev = curr;
        }
    }
    return output;
}



























int main()
{
        TrieNode *root = new TrieNode('-');

        vector<string> v;
        v.push_back("love");
        v.push_back("lover");
        v.push_back("loving");
        v.push_back("last");
        v.push_back("lost");
        v.push_back("lane");
        v.push_back("lord");

        string input = "lovi";

        // insert the above v into trie
        for(int i = 0 ; i<v.size() ; i++){
            insertWord(root , v[i]);
        }

        // Store ans 
        vector<vector<string>>ans =  getSuggestions(root , input);

        for(int i=0 ; i<ans.size() ; i++){
            for(int j=0 ; j<ans[i].size() ; j++){
                cout<<ans[i][j]<<" , ";
            }
            cout<<endl;
        }

}