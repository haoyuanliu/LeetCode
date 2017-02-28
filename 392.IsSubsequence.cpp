class Solution
{
public:
    bool isSubsequence(string s, string t)
    {
        int i = 0;
        int len = s.size();
        if(len == 0)
            return true;
        for(const auto x : t)
        {
            if(x == s[i])
            {
                if(++i == len)
                    return true;
            }
        }
        return false;
    }
};
