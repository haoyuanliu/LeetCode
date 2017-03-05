class Solution
{
public:
    int findContentChildren(vector<int>& g, vector<int>& s)
    {
        int res = 0;
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        for(auto x : s)
        {
            for(int i = 0; i < g.size(); ++i)
            {
                if(g[i] <= x)
                {
                    res++;
                    g.erase(g.begin() + i);
                    break;
                }
            }
        }
        return res;
    }
};
