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

class Solution
{
public:
    int findContentChildren(vector<int>& g, vector<int>& s)
    {
        int res = 0;
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int x = g.size() - 1;
        int y = s.size() - 1;
        while(x >= 0 && y >= 0)
        {
            if(g[x] > s[y]) x--;
            else if(g[x--] <= s[y--]) res++;
        }
        return res;
    }
};
