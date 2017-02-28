class Solution
{
public:
    int wiggleMaxLength(vector<int>& nums)
    {
        int len = nums.size();
        int po = 1;
        int ne = 1;
        for(int i = 1; i < len; ++i)
        {
            if(nums[i] > nums[i-1])
                po = ne + 1;
            else if(nums[i] < nums[i-1])
                ne = po + 1;
        }
        return min(len, max(ne, po));
    }
};
