#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
    public:
        int missingNumber(vector<int> &nums)
        {
            int i;
            sort(nums.begin(), nums.end());
            if(nums[0] > 0)
                return 0;
            for(i = 0; i < nums.size()-1; ++i)
            {
                if(nums[i] + 1 == nums[i+1])
                    continue;
                else
                    return nums[i]+1;
            }
            return nums[i]+1;
        }
};

class Solution
{
    public:
        int missingNumber(vector<int> &nums)
        {
            int res = nums.size();
            for(int i = 0; i < nums.size(); ++i)
            {
                res ^= nums[i];
                res ^= i;
            }
            return res;
        }
};

class Solution
{
    public:
        int missingNumber(vector<int> &nums)
        {
            int res = 0;
            int len = nums.size();
            res = len * (len + 1) / 2;
            for(int i = 0; i < len; ++i)
                res -= nums[i];
            return res;
        }
};

class Solution
{
    public:
        int missingNumber(vector<int> &nums)
        {
            sort(nums.begin(), nums.end());
            int left = 0;
            int right = nums.size();
            int mid = (left + right) / 2;
            while(left < right)
            {
                mid = (left + right) / 2;
                if(mid < nums[mid])
                    right = mid;
                else
                    left = mid+1;
            }
            return left;
        }
};

int main()
{
    return 0;
}
