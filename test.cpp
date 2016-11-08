class Solution
{
    public:
        vector<vector<int>> fourSum(vector<int>& nums, int target)
        {
            vector<vector<int>> res;
            vector<int> temp;
            int len = nums.size();
            int l, r;
            if(len < 4)
                return res;
            sort(nums.begin(), nums.end());
            for(int i = 0; i < len-3; ++i)
            {
                target = target - nums[i];
                for(int j = i+1; j < len-2; ++j)
                {
                    target = target - nums[j];
                    l = j+1;
                    r = len-1;
                    while(l < r)
                    {
                        if(nums[l] + nums[l] < target)
                        {
                            l++;
                        }
                        else if(nums[l] + nums[r] > target)
                        {
                            r--;
                        }
                        else
                        {
                            temp.push_back(nums[i]);
                            temp.push_back(nums[j]);
                            temp.push_back(nums[l]);
                            temp.push_back(nums[r]);
                            res.push_back(temp);
                            temp.clear();
                            while(l < r && nums[l+1] == nums[l])
                                l++;
                            while(l < r && nums[r-1] == nums[r])
                                r--;
                            l++;
                            r--;
                        }
                    }
                    target = target + nums[j];
                    while(j < len-2 && nums[j+1] == nums[j])
                        j++;
                }
                target = target + nums[i];
                while(i < len-3 && nums[i+1] == nums[i])
                    i++;
            }
            return res;
        }
};