class Solution
{
public:
    int maxProfit(vector<int>& prices)
    {
        int res = 0;
        int len = prices.size();
        if(len < 2) return res;
        int cur = 0;
        while(cur+1 < len)
        {
            if(prices[cur] < prices[cur+1])
            {
                res -= prices[cur++];
                while(cur+1 < len && prices[cur] < prices[cur+1])
                    cur++;
                res += prices[cur];
            }
            cur++;
        }
        return res;
    }
};


class Solution
{
public:
    int maxProfit(vector<int>& prices)
    {
        int res = 0;
        for(int i = 1; i < prices.size(); ++i)
        {
            res += max(prices[i] - prices[i-1], 0);
        }
        return res;
    }
};
