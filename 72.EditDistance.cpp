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

int main()
{
    Solution demo;
    string s1, s2;
    while(cin >> s1 >> s2)
        cout << demo.minDistance(s1, s2) << endl;
    return 0;
}
