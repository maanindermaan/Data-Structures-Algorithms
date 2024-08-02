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
    // 9. Pushing the ans string into temp if curr-> isTerminal = true i.e. All common were pushed and if one ends it gets pushed
    if(curr->isTerminal == true){
        temp.push_back(prefix);;
    }

    // 10. Give every option from a to z for everynode next to curr node
    for(char i = 'a' ; i<='z' ; i++){
        // 11. Giving options for next nodes from a-z. Eg-> checking for a. Whether curr->next node has a or not
        char ch = i;

        // 12. finding index of that node from a-z. E.g. a->index = 0;
        int index = ch-'a';

        // 13. Checking whether this element lies in children of curr or not
        TrieNode* next = curr->children[index];

        // 14. If next exits then : 
        if(next != NULL){
            prefix.push_back(ch);

            storeSuggestions(next , temp , prefix);

            prefix.pop_back();
        }
    }
    
}



vector<vector<string>> getSuggestions(TrieNode* root , string input){
    // 1. Create all of the data structured needed
    TrieNode* prev = root;
    vector<vector<string>> output;
    string prefix = "";
    

    // 2. Iterate over input string
    for(int i=0 ; i<input.size(); i++){
        // 3. Find last character which needs to be compared. Here we consider single item as last item
        char lastCh = input[i];

        // 4. Find the index of this character so that i can check for curr Node;
        int index = lastCh-'a';

        // 5. Taking curr node next to previous node
        TrieNode* curr = prev->children[index];

        // 6. Check wheter this curr exits or not
        if(curr == NULL){
            break ;
        }
        else{
            vector<string> temp;
            
            // 7. Store the last character the prefix array
            prefix.push_back(lastCh);

            // 8. Call a function to store suggestion string into vector of temp string
            storeSuggestions(curr , temp , prefix);

            // 16. Output mein push krdo 
            output.push_back(temp);

            // 17. WILL FORGET PAKKA
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
















































// // APPROACH - 2 USING TRIES
// #include <iostream>
// using namespace std;

// class TrieNode
// {
// public:
//     char data;
//     TrieNode *children[26]; // for bache
//     bool isTerminal;
//     int childCount; // we will increase when we will insert

//     TrieNode(char d)
//     {
//         this->data = d;
//         for (int i = 0; i < 26; i++)
//         {
//             children[i] = NULL;
//         }
//         childCount = 0;
//         this->isTerminal = false;
//     }
// };

// void insertWord(TrieNode *root, string word)
// {
//     // cout << "Inserting " << word << endl;
//     // base case
//     if (word.length() == 0)
//     {
//         root->isTerminal = true;
//         return;
//     }

//     char ch = word[0];
//     int index = ch - 'a';
//     TrieNode *child;
//     // present
//     if (root->children[index] != NULL)
//     {
//         child = root->children[index];
//     }
//     else
//     {
//         // not present
//         child = new TrieNode(ch);
//         root->childCount++;
//         root->children[index] = child;
//     }

//     // recursion sambhal lega
//     insertWord(child, word.substr(1));
// }

// bool searchWord(TrieNode *root, string word)
// {
//     // base case -> Jab Last Char Aajaye
//     if (word.length() == 0)
//     {
//         return root->isTerminal;
//     }

//     char ch = word[0];
//     int index = ch - 'a';
//     TrieNode *child;

//     // present
//     if (root->children[index] != NULL)
//     {
//         child = root->children[index];
//     }
//     else
//     {
//         return false;
//     }
//     // rec call
//     return searchWord(child, word.substr(1));
// }

// void findLCP(string& ans , string& first , TrieNode* root){
//     // 1. Check whether the node is empty or not
//     if(root->isTerminal != false){
//         return;
//     }

//     // 2. Now traverse into the tree to find out what is the case
//     for(int i=0 ; i<first.size() ; i++){
//         char ch = first[i];
//         // 3. We can only insert into ans if it's child count is 1 and till terminal node
//         // 1) checking for child count = 1
//         if(root->childCount == 1){
//             ans.push_back(ch);

//             int index = ch - 'a';

//             root = root->children[index];
//         }
//         // 4. if two or more child neglect
//         else{
//             break;
//         }

//         // 2) If terminal Node
//         if(root->isTerminal != false){
//             break;
//         }
//     }
// }

// string longestCommonPrefix(vector<string>& strs){
//     // 1. Make a root node
//     TrieNode* root = new TrieNode('-');

//     // 2. Insert all of the elements into this trie
//     for(int i=0 ; i<strs.size() ; i++){
//         insertWord(root , strs[i]);
//     }

//     // 3. Create a ans string
//     string ans = "";

//     // 4. Suppose you take first string to compare it with others
//     string first = strs[0];

//     // 5. Call a function to find longest common prefix.
//     findLCP(ans , first , root);

//     return ans;
// }

// int main()
// {
//     vector<string> strs;
//     strs.push_back("code");
//     strs.push_back("coder");
//     strs.push_back("codehelp");
//     strs.push_back("codemania");

//     cout << longestCommonPrefix(strs);
//     return 0;
// }