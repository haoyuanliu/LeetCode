#include <iostream>
#include <string>
#include <map>
using namespace std;
 
class Solution {
public:
    int romanToInt(string s) 
    {
        map<char, int> m;
        char ch[] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
        int num[] = {1, 5, 10, 50, 100, 500, 1000};
        for(int i = 0; i < 7; ++i)
        {
            m.insert(make_pair(ch[i], num[i]));
        }
        int res = 0;
        for(int i = 0; i < s.length(); ++i)
        {
            if(m[s[i]] < m[s[i+1]])
                res -= m[s[i]];
            else
                res += m[s[i]];
        }
        return res;
    }
};

int main()
{
    Solution res;
    string str;
    while(cin >> str)
        cout << res.romanToInt(str) << endl;
    return 0;
}