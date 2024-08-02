#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// 1.
int getithBit(int n, int i)
{
  int mask = 1 << i;
  int ans = n & mask;
  if (ans == 0)
    return 0;
  else
    return 1;
}

// 2.
void setithBit(int n, int i)
{
  int mask = 1 << i;
  int ans = n | mask;
  cout << "after setting: " << ans << endl;
}


// 2.
void clearIthBit(int &n, int i)
{
  int mask = ~(1 << i);
  n = n & mask;
  // cout << "aster clearing " << ans << endl;
}

// 3.
void updateIthBit(int &n, int i, int target)
{
  clearIthBit(n, i);
  int mask = target << i;
  // int ans = n | mask;
  n = n | mask;
  cout << "after updating " << n << endl;
}

// 3.
void clearLastIBits(int n, int i)
{
  int mask = (-1 << i);
  n = n & mask;
  cout << "after clearing last i bits: " << n << endl;
}

// 4.
bool checkPowerOf2(int n)
{
  if ((n & (n - 1)) == 0)
    return true;
  else
    return false;
}

// 5
int countSetBits(int n)
{
  int count = 0;
  while (n != 0)
  {
    int lastBit = n & 1;
    if (lastBit)
      count++;
    // right shift
    n = n >> 1;
  }
  return count;
}

// 5
int countSetBitsFast(int n)
{
  int count = 0;
  while (n != 0)
  {
    // remove last set bit
    n = (n & (n - 1));
    count++;
  }
  return count;
}

// 6.
void clearBitsInRange(int n, int i, int j)
{
  int a = (-1 << (i + 1));
  int b = (1 << j) - 1;
  int mask = a | b;
  n = n & mask;
  cout << "after clearing in range " << n << endl;
}

// 8.
void getSubsequences(string str)
{
  vector<string> ans;
  int n = str.length();

  for (int num = 0; num < (1 << n); num++) // 1 ko n baar left shift kro 2^n nikaljayegi
  {
    string temp = "";
    // we will create subsequence string in this temp string
    for (int i = 0; i < n; i++)
    {
      char ch = str[i];
      if (num & (1 << i))
      {
        // non-zero value k liye , include current character
        temp.push_back(ch);
      }
    }

    if (temp.length() >= 0)
    {
      // store in ans
      ans.push_back(temp);
    }
  }
  sort(ans.begin(), ans.end());
  cout << "Count of subsequences " << ans.size() << endl;
  cout << "printing the subsequences" << endl;
  for (auto i : ans)
  {
    cout << i << endl;
  }
}

int main()
{
  //   int n = 50;
  //   if(n & 1) {
  //     cout << "n is odd" << endl;
  //   }
  //   else {
  //     cout << "n is even" << endl;
  //   }
  //     int ans = getithBit(10, 0);
  //     cout << ans << endl;

  //     setithBit(10,2);
  // clearIthBit(10, 1);

  //     int n = 7;
  //     clearLastIBits(n, 2);
  //   cout << (16 & 15) << endl;
  //     cout << "Power of 2 ans: " << checkPowerOf2(3) << endl;
  //     cout << "Number of set bits: " << countSetBitsFast(1024) << endl;
  //     clearBitsInRange(15,3,0);

  string str = "abc";
  getSubsequences(str);

  return 0;
}