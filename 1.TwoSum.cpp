class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        int l = nums.size();
        vector<int> res;
        for(int i = 0; i < l; ++i)
        {
            for(int j = i+1; j < l; ++j)
            {
                if(nums[i] + nums[j] == target)
                {
                    res.push_back(i);
                    res.push_back(j);
                    break;
                }
            }
        }
        return res;
    }
};