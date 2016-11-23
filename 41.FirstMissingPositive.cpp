#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

//Solution 1 6ms
class Solution
{
    public:
        int firstMissingPositive(vector<int>& nums)
        {
            int res = 1;
            sort(nums.begin(), nums.end());
            for(int i = 0; i < nums.size(); ++i)
            {
                if(nums[i] <= 0)
                    continue;
                if(nums[i] == res-1)
                    continue;
                if(nums[i] == res)
                    res = nums[i]+1;
                else
                    return res;
            }
            return res;
        }
};


//Solution 2 3ms
class Solution
{
    public:
        int firstMissingPositive(vector<int> &nums)
        {
            int len = nums.size();
            int temp[len];
            for(int i = 0; i < len; ++i)
            {
                if(nums[i] > 0 && nums[i] <= len)
                    temp[nums[i] - 1] = nums[i];
                else
                    continue;
            }

            for(int i = 0; i < len; ++i)
                if(temp[i] != i+1)
                    return i+1;
            return len+1;
        }
};

//Solution 3 3ms
class Solution
{
    public:
        int firstMissingPositive(vector<int> &nums)
        {
            int len = nums.size();
            for(int i = 0; i < len; )
            {
                if(nums[i] > 0 && nums[i] <= len && nums[i] != nums[nums[i] - 1])
                    swap(nums[i], nums[nums[i] -1]);
                else
                    i++;
            }
            for(int i = 0; i < len; ++i)
                if(nums[i] != i+1)
                    return i+1;
            return len+1;
        }
};

int main()
{
    Solution demo;
    int temp;
    vector<int> nums;
    while(cin >> temp)
    {
        nums.push_back(temp);
    }
    cout << demo.firstMissingPositive(nums) << endl;
    return 0;
}
