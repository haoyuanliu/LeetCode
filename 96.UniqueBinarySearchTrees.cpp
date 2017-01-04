class Solution 
{
public:
    int numTrees(int n) 
    {
        vector<int> res(n+1, 0);
        res[0] = 1;
        res[1] = 1;
        res[2] = 2;
        for(int i = 3; i <= n; ++i)
        {
        	res[i] += res[i-1] * 2;
        	for(int j = 1; j < i-1; ++j)
        	{
        		res[i] += res[j] * res[i-j-1];
        	}
        }
        return res[n];
    }
};