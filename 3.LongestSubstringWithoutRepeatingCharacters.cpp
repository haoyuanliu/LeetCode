class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
        int len = s.length();
        int i = 0;
        int j = 0;
        int res = 0;
        bool exit[256] = {false};
        while(j < len)
        {
            if(exit[s[j]])
            {
                res = max(res, j - i);
                while(s[i] != s[j])
                {
                    exit[s[i]] = false;
                    i++;
                }
                i++;
                j++;
            }
            else
            {
                exit[s[j]] = true;
                j++;
            }
        }
        res = max(res, len - i);
        return res;
    }
};