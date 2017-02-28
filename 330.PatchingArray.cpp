class Solution
{
public:
    int minPatches(vector<int>& nums, int n)
    {
        int len = nums.size();
        int res = 0;
        int cur = 0;
        long miss = 1;
        while(miss <= n)
        {
            if(cur < len && nums[cur] <= miss)
            {
                miss += nums[cur++];
            }
            else
            {
                miss <<= 1;
                res++;
            }
        }
        return res;
    }
};
