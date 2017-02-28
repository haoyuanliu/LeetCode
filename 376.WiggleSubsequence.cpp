class Solution
{
public:
    int wiggleMaxLength(vector<int>& nums)
    {
        int len = nums.size();
        int pos = 1;
        int neg = 1;
        for(int i = 1; i < len; ++i)
        {
            if(nums[i] > nums[i-1])
                pos = neg + 1;
            else if(nums[i] < nums[i-1])
                neg = pos + 1;
        }
        return min(len, max(neg, pos));
    }
};
