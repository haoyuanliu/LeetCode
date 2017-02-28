class Solution
{
public:
    string removeKdigits(string num, int k)
    {
        int len = num.size();
        string res = "";
        int drop = k;
        for(int i = 0; i < len; ++i)
        {
            while(drop && res.size() && num[i] < res.back())
            {
                res.pop_back();
                drop--;
            }
            res += num[i];
        }
        while(drop && res.size())
        {
            res.pop_back();
            drop--;
        }
        while(res[0] == '0')
            res.erase(res.begin());
        return res.empty() ? "0" : res;
    }
};
