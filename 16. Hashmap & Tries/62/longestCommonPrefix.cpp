// APPROACH - 2 USING TRIES
#include <iostream>
using namespace std;

class TrieNode
{
public:
    char data;
    TrieNode *children[26]; // for bache
    bool isTerminal;
    int childCount; // we will increase when we will insert

    TrieNode(char d)
    {
        this->data = d;
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        childCount = 0;
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
        root->childCount++;
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

void findLCP(string first, string &ans, TrieNode *root)
{ // first -> code
 
    // For empty string
    if (root->isTerminal != false)
    {
        return;
    }

    for (int i = 0; i < first.size(); i++)
    {
        char ch = first[i];

        // Agar mere root ke paas ek hi child hai to mai uss child ki value ko ans mein include karlunga
        // or mai uspar chalajaunga
        // check how many child are there;
        if (root->childCount == 1)
        {
            ans.push_back(ch);
            int index = ch - 'a';

            // we also have to go to the child
            // root ko aage badado
            root = root->children[index];
        }

        else
        {
            // root ke paas 2 child hai
            break;
        }

        // Agar root hi terminal hui toh
        if (root->isTerminal != false)
        {
            break;
        }
    }
}

string longestCommonPrefix(vector<string> &strs)
{
    // 1. Create a NULL character or trie
    TrieNode *root = new TrieNode('-');

    // 2. Insert all the strings into trieNode
    for (int i = 0; i < strs.size(); i++)
    {
        insertWord(root, strs[i]);
    }

    // 3. Ans string banalo
    string ans = "";

    string first = strs[0]; // for traversing

    // 4. Function to find LCP
    findLCP(first, ans, root);

    return ans;
}

int main()
{
    vector<string> strs;
    strs.push_back("code");
    strs.push_back("coder");
    strs.push_back("codehelp");
    strs.push_back("codemania");

    cout << longestCommonPrefix(strs);
    return 0;
}

// APPROACH - 1 BRUTE FORCE
// #include<iostream>
// using namespace std;

// string longestCommonPrefix(vector<string>& strs){
//     string ans = "";
//     // loop on first string
//     for(int i=0 ; i<strs[0].size() ; i++){
//         char ch = strs[0][i];
//         bool match = true;

//         // compare this character with other strings
//         for(int j=1 ; j<strs.size() ; j++){
//             if(strs[j].size() < i || ch != strs[j][i]){
//                 match = false;
//                 break;
//             }
//         }

//         if(match == false){
//             break;
//         }
//         else{
//             ans.push_back(ch);
//         }
//     }
//     return ans;
// }

// int main(){
//     vector<string> strs;
//     strs.push_back("flower");
//     strs.push_back("flow");
//     strs.push_back("flight");

//     cout<<longestCommonPrefix(strs);
// return 0;
// }