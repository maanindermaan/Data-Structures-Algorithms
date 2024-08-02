#include <iostream>
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

void deleting(TrieNode *root, string word)
{
        if (word.empty())
        {
                root->isTerminal = false;
                return;
        }

        char ch = word[0];
        int index = ch - 'a';
        TrieNode *child = root->children[index];

        if (child != NULL)
        {
                deleting(child, word.substr(1));

                // If the child node has no other children and is not a terminal node, delete it
                if (child->isTerminal != false)
                {
                        delete child;
                        root->children[index] = NULL;
                }
        }
}

void deleting2(TrieNode *root, string word)
{
        if (word.empty())
        {
                root->isTerminal = false;
                return;
        }

        char ch = word[0];
        int index = ch - 'a';
        TrieNode *child;

        if (child != NULL)
        {
                child = root->children[index];
                deleting2(child, word.substr(1));

                // ab uss particular node ka isTerminal agar false nahi hai toh use delete krdo
                if (child->isTerminal != false)
                {
                        delete child;
                        // or uske children wale mein ab kuch nahi pada toh use bhi update krdo
                        root->children[index] = NULL;
                }
        }
}

int main()
{
        TrieNode *root = new TrieNode('-');

        // root->insertWord("coding");
        insertWord(root, "coding");
        insertWord(root, "code");
        insertWord(root, "coder");
        insertWord(root, "codehelp");
        insertWord(root, "baba");
        insertWord(root, "baby");
        insertWord(root, "babu");
        insertWord(root, "shona");
        cout << "Searching " << endl;
        if (searchWord(root, "shona"))
        {
                cout << "shona present" << endl;
        }
        else
        {
                cout << "shona absent" << endl;
        }

        deleting(root, "shona");

        if (searchWord(root, "shona"))
        {
                cout << "shona present" << endl;
        }
        else
        {
                cout << "shona absent" << endl;
        }

        cout << endl;
        cout << endl;
        cout << endl;
        if (searchWord(root, "coding"))
        {
                cout << "coding present" << endl;
        }
        else
        {
                cout << "coding absent" << endl;
        }

        deleting(root, "coding");

        if (searchWord(root, "coding"))
        {
                cout << "coding present" << endl;
        }
        else
        {
                cout << "coding absent" << endl;
        }

        cout << endl;
        cout << endl;
        cout << endl;

        if (searchWord(root, "codehelp"))
        {
                cout << "codehelp present" << endl;
        }
        else
        {
                cout << "codehelp absent" << endl;
        }

        deleting(root, "codehelp");

        if (searchWord(root, "codehelp"))
        {
                cout << "codehelp present" << endl;
        }
        else
        {
                cout << "codehelp absent" << endl;
        }
        return 0;
}