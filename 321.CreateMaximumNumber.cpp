class Solution
{
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k)
    {
        int n1 = nums1.size();
        int n2 = nums2.size();
        vector<int> res;
        for(int i = max(0, k - n2); i <= min(k, n1); ++i)
        {
            res = max(res, maxNumber(maxNumber(nums1, i), maxNumber(nums2, k-i)));
        }
        return res;
    }

    vector<int> maxNumber(vector<int> nums, int k)
    {
        int drop = nums.size() - k;
        vector<int> res;
        for(const auto n : nums)
        {
            while(drop && !res.empty() && n > res.back())
            {
                res.pop_back();
                drop--;
            }
            res.push_back(n);
        }
        res.resize(k);
        return res;
    }

    vector<int> maxNumber(vector<int> nums1, vector<int> nums2)
    {
        vector<int> res;
        while(nums1.size() + nums2.size())
        {
            vector<int> &temp = nums1 > nums2 ? nums1 : nums2;
            res.push_back(temp[0]);
            temp.erase(temp.begin());
        }
        return res;
    }
};
