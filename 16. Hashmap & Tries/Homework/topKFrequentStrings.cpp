// // USING HASHMAPS
// #include <iostream>
// #include <vector>
// #include <queue>
// #include <unordered_map>
// #include <climits>
// using namespace std;

// vector<string> stopKFrequent(vector<string> &words, int k)
// {
//     vector<string> ans;
//     // 1. Create mapping
//     unordered_map<string, int> mapping; //{word , occurrence}

//     // store the occurrence of string
//     for (int i = 0; i < words.size(); i++)
//     {
//         mapping[words[i]]++;
//     }

//     priority_queue<pair<int, string>> pq; // Max-heap to sort by occurrence

//     for (auto it = mapping.begin(); it != mapping.end(); it++)
//     {
//         pq.push({it->second, it->first});
//     }

//     while (k > 0 && !pq.empty())
//     {
//         ans.push_back(pq.top().second);
//         pq.pop();
//         k--;
//     }

//     return ans;
// }

// int main()
// {
//     vector<string> words;
//     words.push_back("i");
//     words.push_back("love");
//     words.push_back("leetcode");
//     words.push_back("i");
//     words.push_back("love");
//     words.push_back("coding");

//     int k = 2;

//     vector<string> ans = stopKFrequent(words, k);

//     for (int i = 0; i < ans.size(); i++)
//     {
//         cout << ans[i] << " ";
//     }
//     return 0;
// }

// // USING TRIES
// #include <iostream>
// #include <algorithm>
// #include <vector>
// #include <queue>
// #include <unordered_map>
// #include <climits>
// using namespace std;

// class comp
// {
// public:
//     bool operator()(const pair<int, string> &a, const pair<int, string> &b)
//     {
//         // return a.first == b.first ? a<b : a.first > b.first;
//         if (a.first == b.first)
//         {
//             return a < b;
//         }
//         else
//         {
//             return a.first > b.first;
//         }
//     }
// };

// class TrieNode
// {
// public:
//     char data;
//     TrieNode *children[26];
//     bool isTerminal;
//     int freq;

//     TrieNode(char d)
//     {
//         this->data = d;
//         for (int i = 0; i < 26; i++)
//         {
//             children[i] = NULL;
//         }
//         this->isTerminal = false;
//         this->freq = 0;
//     }
// };

// class Trie
// {
//     TrieNode *root;

//     void insertWord(TrieNode *root, string &word, int i)
//     {
//         if (i >= word.size())
//         {
//             root->isTerminal = true;
//             // count located at terminal node
//             ++root->freq;
//             return;
//         }

//         char ch = word[i];
//         int index = ch - 'a';

//         if (!root->children[index])
//         {
//             root->children[index] = new TrieNode(ch);
//         }

//         insertWord(root->children[index], word, i + 1);
//     }

//     void traverseUtil(TrieNode *root, string &s, priority_queue<pair<int, string>, vector<pair<int, string>, comp>> &pq, int &k)
//     {
//         if (!root)
//         {
//             return;
//         }

//         // stores k frequent words
//         if (root->isTerminal)
//         {
//             if (pq.size() < k)
//             {
//                 pq.push({root->freq, s});
//             }
//             else if (root->freq > pq.top().first)
//             {
//                 pq.pop();
//                 pq.push({root->freq, s});
//             }
//         }

//         // we have to search for every digit at every node
//         for (int i = 0; i < 26; i++)
//         {
//             if (root->children[i])
//             {
//                 s.push_back(i + 'a'); // int to char conversion
//                 traverseUtil(root->children[i], s, pq, k);

//                 // for multiple children ek ko process kiya then backtrack then dusri ko process kiya
//                 s.pop_back(); // backtracking
//             }
//         }
//     }

// public:
//     Trie()
//     {
//         root = new TrieNode('\0');
//     }

//     void insert(string word)
//     {
//         insertWord(root, word, 0);
//     }

//     void traverse(priority_queue<pair<int, string>, vector<pair<int, string>, comp>> &pq, int k)
//     {

//         // while traversing over strings it is needed to concatanate characters to form string
//         string s;
//         traverseUtil(root, s, pq, k);
//     }
// };

// vector<string> topKFrequent(vector<string> &words, int k)
// {
//     Trie trie;
//     vector<string> ans;

//     // insert into trie
//     for (int i = 0; i < words.size(); i++)
//     {
//         trie.insert(words[i]);
//     }

//     // find k frequent words
//     priority_queue<pair<int, string>, vector<pair<int, string>, comp>> pq;

//     // traverse the whole trie and insert into priority queue
//     trie.traverse(pq, k);

//     while (!pq.empty())
//     {
//         auto top = pq.top();
//         pq.pop();
//         ans.push_back(top.second);
//     }
//     reverse(ans.begin(), ans.end());
//     return ans;
// }

// int main()
// {
//     vector<string> words;
//     words.push_back("i");
//     words.push_back("love");
//     words.push_back("leetcode");
//     words.push_back("i");
//     words.push_back("love");
//     words.push_back("coding");

//     int k = 2;

//     vector<string> ans = topKFrequent(words, k);

//     for (int i = 0; i < ans.size(); i++)
//     {
//         cout << ans[i] << " ";
//     }
//     return 0;
// }



#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <unordered_map>
#include <climits>
using namespace std;

class comp
{
public:
    bool operator()(const pair<int, string> &a, const pair<int, string> &b)
    {
        using value_type = pair<int, string>;
        if (a.first == b.first)
        {
            return a < b;
        }
        else
        {
            return a.first > b.first;
        }
    }
};

class TrieNode
{
public:
    char data;
    TrieNode *children[26];
    bool isTerminal;
    int freq;

    TrieNode(char d)
    {
        this->data = d;
        for (int i = 0; i < 26; i++)
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
        int index = ch - 'a';

        if (!root->children[index])
        {
            root->children[index] = new TrieNode(ch);
        }

        insertWord(root->children[index], word, i + 1);
    }

    void traverseUtil(TrieNode *root, string &s, priority_queue<pair<int, string>, vector<pair<int, string>>, comp> &pq, int k)
    {
        if (!root)
        {
            return;
        }

        if (root->isTerminal)
        {
            if (pq.size() < k)
            {
                pq.push({root->freq, s});
            }
            else if (root->freq > pq.top().first)
            {
                pq.pop();
                pq.push({root->freq, s});
            }
        }

        for (int i = 0; i < 26; i++)
        {
            if (root->children[i])
            {
                s.push_back(i + 'a');
                traverseUtil(root->children[i], s, pq, k);
                s.pop_back();
            }
        }
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

    void traverse(priority_queue<pair<int, string>, vector<pair<int, string>>, comp> &pq, int k)
    {
        string s;
        traverseUtil(root, s, pq, k);
    }
};

vector<string> topKFrequent(vector<string> &words, int k)
{
    Trie trie;
    vector<string> ans;

    for (int i = 0; i < words.size(); i++)
    {
        trie.insert(words[i]);
    }

    priority_queue<pair<int, string>, vector<pair<int, string>>, comp> pq;

    trie.traverse(pq, k);

    while (!pq.empty())
    {
        auto top = pq.top();
        pq.pop();
        ans.push_back(top.second);
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main()
{
    vector<string> words;
    words.push_back("i");
    words.push_back("love");
    words.push_back("leetcode");
    words.push_back("i");
    words.push_back("love");
    words.push_back("coding");

    int k = 2;

    vector<string> ans = topKFrequent(words, k);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}

