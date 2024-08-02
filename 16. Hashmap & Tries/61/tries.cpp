#include <iostream>
using namespace std;

class TrieNode
{
public:
    char data;
    TrieNode *children[26];
    bool isTerminal;

    TrieNode(char data)
    {
        this->data = data;
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        this->isTerminal = false;
    }
};

void insertWord(TrieNode *root, string word)
{
    if (word.length() == 0)
    {
        root->isTerminal = true;
        return;
    }

    char ch = word[0];
    int index = ch-'a';
    TrieNode* child; // child node

    if(root->children[index] != NULL){
        child = root->children[index];
    }
    else{
        // Present nahi hai to create karo
        child = new TrieNode(ch);
        root->children[index] = child;
    }

    // Recursive Call
    insertWord(child , word.substr(1));

}

int main()
{

    return 0;
}