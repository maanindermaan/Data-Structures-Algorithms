#include <iostream>
#include <vector>
using namespace std;

class TrieNode
{
public:
    char data;
    TrieNode *children[58]; // 1.size doubled due to upper case letters also
    bool isTerminal;
    int freq;

    TrieNode(char d)
    {
        this->data = d;
        for (int i = 0; i < 58; i++)
        {
            children[i] = NULL;
        }
        this->isTerminal = false;
        this->freq = 0;
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
            ++root->freq;
            return;
        }

        char ch = word[i];
        int index = ch - 'A';

        if (!root->children[index])
        {
            root->children[index] = new TrieNode(ch);
        }

        insertWord(root->children[index], word, i + 1);
    }

    bool searchWord(TrieNode *root, string &word, int i)
    {
        if (i >= word.size())
        {
            return root->isTerminal;
        }

        int index = word[i] - 'A'; // 2. captial letter

        if (root->children[index])
        {
            return searchWord(root->children[index], word, i + 1);
        }
        // for lower case
        // else if(islower(word[i])){ // 5. agar yeah true hai toh
        //     return searchWord(root , word , i+1); // 6. mai aage children pe moove hi nahi karunga consume karadunga lower walo ko. mai root pe hi rahunga aage move ni karunag
        // }
        else if (islower(word[i]))
        {
            return searchWord(root, word, i + 1);
        }

        return false;
    }

public:
    Trie()
    {
        root = new TrieNode('\0');
    }

    void insert(string &word)
    {
        insertWord(root, word, 0);
    }

    bool search(string &word)
    {
        return searchWord(root, word, 0);
    }
};

vector<bool> camelCaseMatching(vector<string> &quaries, string pattern)
{
    vector<bool> ans;

    Trie trie;

    trie.insert(pattern);

    // 3. now traverse over quaries array and put it back into ans array
    for (int i = 0; i < quaries.size(); i++)
    {
        ans.push_back(trie.search(quaries[i])); // 4. modify the search now
    }
    // for(auto query : quaries){
    //     ans.push_back(search(query));
    // }

    return ans;
}

int main()
{
    vector<string> quaries = {
        {"FootBall"},
        {"FootBallReal"},
        {"FooooootBbbbb"},
        {"FootmanchestuitedBanchod"}};

    string pattern = "FoBa";

    vector<bool> ans = camelCaseMatching(quaries, pattern);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}