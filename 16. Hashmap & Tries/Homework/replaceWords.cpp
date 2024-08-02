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

// int searchWord(TrieNode *root, string word)
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
//         return -1;
//     }
//     // rec call
//     int ans = searchWord(child, word.substr(1));
//     return ans;
// }

// string replaceWords(vector<string> &dictionary, string sentence)
// {
//     // 1. answer string banalo
//     string ans;

//     // 2. Dictionary ko uthake trie mein insert kardo
//     TrieNode* root;

//     // 3. Put all elements of dictionary into Trie
//     for(int i=0 ; i<dictionary.size() ; i++){
//         insertWord(root , dictionary[i]);
//     }

//     // 4. Pick each word and find in trie whether root is available or not
//     int start = 0 , end = 0;
//     while(end < sentence.size()){
//         if(sentence[end] == ' ' || sentence[end] == sentence.size()-1){
//             int length = 0;
//             if(end == sentence.size()-1){
//                 length = sentence.size();
//             }
//             else{
//                 length = end - start;
//             }
//             string word = sentence.substr(start , length);
//             int trieMatchIndex = searchWord(root , word);

//             if(trieMatchIndex != -1){
//                 word.substr(0,trieMatchIndex);
//             }
//             if(sentence[end] == ' '){
//                 ans += " ";
//             }
//             start = end + 1;
//         }
//         ++end;
//     }
//     return ans;
// }

// int main()
// {
//     vector<string> dictionary;
//     dictionary.push_back("cat");
//     dictionary.push_back("bat");
//     dictionary.push_back("rat");

//     string sentence = "the catttle was rattled by battery";

//     cout << replaceWords(dictionary, sentence);

//     return 0;
// }

#include <iostream>
#include <vector>
using namespace std;

class TrieNode
{
public:
    char data;
    TrieNode *children[26];
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

class Trie
{
    TrieNode *root;

    void insertWord(TrieNode *root, string &word, int i)
    {
        if (i >= word.size())
        {
            root->isTerminal = true;
            return;
        }

        char ch = word[i];
        int index = ch - 'a';

        if (!root->children[index])
        {
            root->children[index] = new TrieNode(ch);
        }

        insertWord(root->children[index], word, i + 1);
    }

    bool searchWord(TrieNode *root, string &word, int &i)
    {
        if (root->isTerminal)
        {
            return true;
        }
        if (i >= word.size())
        {
            return root->isTerminal;
        }

        int index = word[i] - 'a';

        if (root->children[index])
        {
            return searchWord(root->children[index], word, ++i);
        }
        return false;
    }

public:
    Trie()
    {
        root = new TrieNode('\0');
    }

    void insert(string word)
    {
        insertWord(root, word, 0);
    }

    bool search(string word)
    {
        int i = 0;
        return searchWord(root, word, i);
    }
};

string replaceWords(vector<string> &dictionary, string sentence)
{
    string ans;
    Trie trie;

    for (auto root : dictionary)
    {
        trie.insert(root);
    }

    int start = 0, end = 0;
    while (end < sentence.size())
    {
        if (sentence[end] == ' ' || end == sentence.size() - 1)
        {
            int length = end == sentence.size() - 1 ? sentence.size() - start : end - start + 1;
            string word = sentence.substr(start, length);
            int trieMatchIndex = -1;

            for (int i = 1; i <= word.size(); i++)
            {
                if (trie.search(word.substr(0, i)))
                {
                    trieMatchIndex = i;
                    break;
                }
            }

            ans += (trieMatchIndex != -1) ? word.substr(0, trieMatchIndex) : word;
            if (sentence[end] == ' ')
            {
                ans += " ";
            }
            start = end + 1;
        }
        ++end;
    }
    return ans;
}

int main()
{
    vector<string> dictionary;
    dictionary.push_back("cat");
    dictionary.push_back("bat");
    dictionary.push_back("rat");

    string sentence = "the catttle was rattled by battery";

    cout << replaceWords(dictionary, sentence);

    return 0;
}
