#include <iostream>
#include <string>
using namespace std;

class Solution
{
    public:
        string longestPalindrome(string s)
        {
            int p, q, max;
            int start, end;
            p = q = max = 0;
            string str = '&' + s;
            int len = str.length();
            for(int i = 1; i < len; ++i)
            {
                p = i;
                while(s[i] == s[i+1])
                    i++;
                q = i;
                while(s[p-1] == s[q+1])
                {
                    p--;
                    q++;
                }
                if(max < (q-p+1))
                {
                    start = p;
                    end = q;
                    max = q-p+1;
                }
            }
            str = str.substr(start+1, max);
            return str;
        }
};

int main()
{
    string str;
    Solution res;
    while(cin >> str)
    {
        cout << res.longestPalindrome(str) << endl;
    }
    return 0;
}
