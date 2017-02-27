class Solution
{
public:
    int candy(vector<int>& ratings)
    {
        int res = 0;
        int len = ratings.size();
        if(len < 2) return len;
        vector<int> candies(len, 1);
        for(int i = 1; i < len; ++i)
        {
            if(ratings[i] > ratings[i-1])
                candies[i] = candies[i-1] + 1;
        }

        for(int i = len-2; i >= 0; --i)
        {
            if(ratings[i] > ratings[i+1])
                candies[i] = max(candies[i+1]+1, candies[i]);
        }
        for(int i = 0; i < len; ++i)
            res += candies[i];
        return res;
    }
};
