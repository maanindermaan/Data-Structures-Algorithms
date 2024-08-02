// #include <iostream>
// #include <queue>
// #include <unordered_set>
// #include <vector>
// using namespace std;

// int ladderLength(string beginWord, string endWord, vector<string> &wordList)
// {
//     queue<pair<string, int>> q;
//     q.push({beginWord, 1});
//     unordered_set<string> st(wordList.begin(), wordList.end());
//     // jo bhi word queue me insert karunga, toh usko set me se remove krdunga
//     st.erase(beginWord);

//     while (!q.empty())
//     {
//         pair<string, int> fNode = q.front();
//         q.pop();

//         string currString = fNode.first;
//         int currCount = fNode.second;

//         // check kahin destination tak toh nahi pohoch gye
//         if (currString == endWord)
//             return currCount;

//         // charcter replacement wala kaam kro
//         for (int index = 0; index < currString.length(); index++)
//         {
//             // hr index pr jo value h, usko main 'a' to 'z' se replace karunga
//             char originalCharacter = currString[index];
//             for (char ch = 'a'; ch <= 'z'; ch++)
//             {
//                 // jo bhi currString ke index pe value hai use replace karwado
//                 currString[index] = ch;
//                 // humne bola ki jo bhi new String create ki hai yeah mere set ke andar present hai, agar present hoti hai toh mai queue mein insert krta hu
//                 // check in wordList
//                 // kya ye nayi wali string word list mein present hai ke nahi hai
//                 if (st.find(currString) != st.end())
//                 {
//                     // exists
//                     q.push({currString, currCount + 1});
//                     // queue mein insert karane ke bad set se remove karadena
//                     st.erase(currString);
//                 }
//             }
//             // bringing back the currString to its original State becuase i want every changes to be made to
//             // orignal string becuase, e.g. hot -> aot , bot ... zot and now next while exiting the current
//             // value will be zot but i want the value to be hot only for next changes
//             currString[index] = originalCharacter;
//         }
//     }
//     return 0;
// }

// int main()
// {
//     string beginWord = "hit";
//     string endWord = "cog";

//     vector<string> wordList = {"hot", "dot", "dog", "lot", "log", "cog"};

//     cout << ladderLength(beginWord, endWord, wordList);

//     return 0;
// }

// practice
#include <iostream>
#include <queue>
#include <unordered_set>
#include <vector>
using namespace std;

int ladderLength(string beginWord, string endWord, vector<string> &wordList)
{
    // 1. create a queue
    queue<pair<string, int>> q;

    // 2. Create a unordered set to store the wordList becuase i want to delete what i have inserted
    unordered_set<string> st(wordList.begin(), wordList.end());

    // 3. Push initial element to queue
    q.push({beginWord, 1});
    // note:- we dont have to erase begin word from set because beginword is not in wordlist so not in set

    // 4. traverse while queue is not empty
    while (!q.empty())
    {
        // 5. fetch top elements
        pair<string, int> fNode = q.front();
        // 6. Remove this from QUEUE as well
        q.pop();

        string currString = fNode.first;
        int currCount = fNode.second;

        // 7. check whether if it is destination node or not
        if (currString == endWord)
        {
            return currCount;
        }

        // 8. Now we are starting our replace logic
        for (int i = 0; i < currString.length(); i++)
        {
            // 9. Finding the char from string to be replaced
            char origChar = currString[i];
            // 10. we are giving a-z total 26 options for that position apart from the word itself (25 options)
            for (char ch = 'a'; ch <= 'z'; ch++)
            {
                currString[i] = ch;
                // 11. checking whether this is present in the set or not if present in set insert it into queue
                if (st.find(currString) != st.end())
                {
                    q.push({currString, currCount + 1});
                    // 12. Now if inserted into queue remove this string from the set so that there is no duplicacy
                    st.erase(currString);
                }
            }
            // 13 . convert the ended modified string to org string for other operations if not found
            currString[i] = origChar;
        }
    }
    return 0;
}

int main()
{
    string beginWord = "hit";
    string endWord = "cog";

    vector<string> wordList = {"hot", "dot", "dog", "lot", "log", "cog"};

    cout << ladderLength(beginWord, endWord, wordList);

    return 0;
}