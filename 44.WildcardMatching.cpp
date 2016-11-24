#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

/*class Solution
{
    public:
        bool isMatch(string s, string p)
        {
            int m = s.size();
            int n = p.size();
            int cnt = count(p.begin(), p.end(), '*');
            if(n - cnt > m)
                return false;
            vector<bool> dp(n+1, false);
            dp[0] = 1;
            for(int j = 1; j <= n; ++j)
                if(p[j-1] == '*')
                    dp[j] = dp[j-1];
            for(int i = 1; i <= m; ++i)
            {
                vector<bool> cur(n+1, false);
                for(int j = 1; j <= n; j++)
                {
                    if(p[j-1] == '*')
                    {
                        cur[j] = dp[j] || cur[j-1];
                    }
                    else
                    {
                        if(s[i-1] == p[j-1] || p[j-1] == '?')
                            cur[j] = dp[j-1];
                    }
                }
                dp = cur;
            }
            return dp[n];

        }
};*/

class Solution
{
    public:
        bool isMatch(string s, string p)
        {
            int m = s.size();
            int n = p.size();
            int cnt = count(p.begin(), p.end(), '*');
            if(n - cnt > m)
                return false;
            vector<bool> dp(n+1, false);
            dp[0] = 1;
            for(int i = 0; i < n; ++i)
                if(p[i] == '*')
                    dp[i+1] = dp[i];
            for(int i = 1; i <= m; ++i)
            {
                vector<bool> cur(n+1, false);
                for(int j = 1; j <= n; ++j)
                {
                    if(p[j-1] == '*')
                        cur[j] = cur[j-1] || dp[j];
                    else
                    {
                        if(p[j-1] == s[i-1] || p[j-1] == '?')
                            cur[j] = dp[j-1];
                    }
                }
                dp = cur;
            }
            return dp[n];
        }
};

int main()
{
    Solution demo;
    string s1, s2;
    while(cin >> s1 >> s2)
    {
        if(demo.isMatch(s1, s2))
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}
