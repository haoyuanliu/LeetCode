#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution
{
    public:
        char findTheDifference(string s, string t)
        {
            char res;
            vector<int> c1(26, 0);
            vector<int> c2(26, 0);
            for(auto const c : s)
                c1[c - 'a']++;
            for(auto const c : t)
            {
                if(++c2[c - 'a'] > c1[c - 'a'])
                {
                    res = c;
                }
            }
            return res;
        }
};

int main()
{
    return 0;
}
