#include <iostream>
#include <string>
using namespace std;

//Solution I TLE
class Solution
{
    public:
        int minDistance(string word1, string word2)
        {
            return step(word1, word2);
        }

        int step(string s1, string s2)
        {
            int m = s1.size();
            int n = s2.size();
            if(!m || !n)
                return max(m, n);
            for(int i = 0; i < min(m, n); ++i)
            {
                if(s1[i] == s2[i])
                    continue;
                else
                {
                    return min(step(s1.substr(i+1), s2.substr(i+1))+1, min(step(s1.substr(i), s2.substr(i+1))+1, step(s1.substr(i+1), s2.substr(i))+1));
                }
            }
            return abs(m - n);
        }
};


//Solution II
class Solution
{
    public:
        int minDistance(string word1, string word2)
        {
            int m = word1.size();
            int n = word2.size();
            vector<vector<int> > dp(m+1, vector<int>(n+1, 0));
            for(int i = 1; i <= m; ++i)
                dp[i][0] = i;
            for(int j = 1; j <= n; ++j)
                dp[0][j] = j;
            for(int i = 1; i <= m; ++i)
            {
                for(int j = 1; j <= n; ++j)
                {
                    dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + 1;
                    if(word1[i-1] == word2[j-1])
                        dp[i][j] = min(dp[i-1][j-1], dp[i][j]);
                    else
                        dp[i][j] = min(dp[i-1][j-1]+1, dp[i][j]);
                }
            }
            return dp[m][n];
        }
};

int main()
{
    Solution demo;
    string s1, s2;
    while(cin >> s1 >> s2)
        cout << demo.minDistance(s1, s2) << endl;
    return 0;
}
