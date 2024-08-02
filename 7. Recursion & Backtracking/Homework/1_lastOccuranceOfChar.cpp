#include <iostream>
using namespace std;

int lastOccurance(string s, char key, int i)
{
    // Base Case
    if (i >= s.size())
    {
        return -1;
    }

    // Baaki recursion sambhal lega
    int ans = lastOccurance(s, key, i + 1);

    // post recursion method ek baar last mein aagye ab ek ek krke i will check ki konse pe tha last se first ki taraf jayenge isme hum 
    // Ek Solve Kardo
    if (ans == -1 && s[i] == key)
    {
        ans = i;
    }

    return ans;
}
int main()
{
    string s = "maan";
    char key = 'a';
    int i = 0;

    int ans = lastOccurance(s, key, i);
    cout << ans;
    return 0;
}




// 2nd method
#include <iostream>
#include <string>

int lastOcc(std::string &s, char ch, int i)
{
    // base cases
    if (i < 0)
    {
        return -1;
    }
    if (s[i] == ch)
    {
        return i;
    }

    return lastOcc(s, ch, i - 1);
}

int main()
{
    std::string str = "hello";
    char searchChar = 'l';
    int i = str.size() - 1;

    int lastIndex = lastOcc(str, searchChar, i);
    std::cout << "Last index of '" << searchChar << "' in \"" << str << "\" is: " << lastIndex << std::endl;
    return 0;
}
