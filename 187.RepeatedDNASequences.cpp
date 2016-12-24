#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

//Solution I TLE
class Solution
{
    public:
        vector<string> findRepeatedDnaSequences(string s)
        {
            map<string, int> str;
            vector<string> res;
            for(int i = 0; i < s.size()-10; ++i)
            {
                string temp = s.substr(i, 10);
                str[temp]++;
            }
            for(auto const x : str)
            {
                if(x.second > 1)
                    res.push_back(x.first);
            }
            return res;
        }
};

//Solution II
class Solution
{
    public:
        vector<string> findRepeatedDnaSequences(string s)
        {
            unordered_map<int, int> m;
            vector<string> res;
            int temp = 0;
            for(int i = 0; i < s.size(); ++i)
            {
                if(m[temp = temp << 3 & 0x3FFFFFFF | s[i] & 7]++ == 1)
                    res.push_back(s.substr(i-9, 10));
            }
            return res;
        }
};

int main()
{
    return 0;
}
