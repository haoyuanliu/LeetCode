#include <iostream>
#include <string>
using namespace std;

class Solution
{
    public:
        int strStr(string haystack, string needle)
        {
            if(needle == "")
                return 0;
            int sLen = haystack.length();
            int pLen = needle.length();
            int next[pLen];
            int res = -1;
            int i, j, k;
            k = -1;
            i = 0;
            next[0] = -1;
            while(i < pLen-1)
            {
                if(k==-1 || needle[i]==needle[k])
                {
                    i++;
                    k++;
                    if(needle[i] == needle[k])
                        next[i] = next[k];
                    else
                        next[i] = k;
                }
                else
                    k = next[k];
            }
            i = j = 0;
            while(i < sLen)
            {
                if(j==-1 || needle[j] == haystack[i])
                {
                    i++;
                    j++;
                }
                else
                {
                    j = next[j];
                }
                if(j == pLen)
                {
                    res = i - pLen;
                    return res;
                }
            }
            return res;
        }
};

int main()
{
    Solution res;
    string haystack, needle;
    while(cin >> haystack >> needle)
        cout << res.strStr(haystack, needle);
    return 0;
}
