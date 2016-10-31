## Brute Force
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
## OnePass Hash Table
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        int l = nums.size();
        vector<int> res;
        map<int, int> m;
        map<int, int>::iterator it;
        for(int i = 0; i < l; ++i)
        {
            int another = target - nums[i];
            it = m.find(another);
            if(it == m.end())
            {
                m.insert(make_pair(nums[i], i));
            }
            else
            {
                res.push_back(it->second);
                res.push_back(i);
            }
        }
        return res;
    }
};