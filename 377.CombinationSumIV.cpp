#include <iostream>
#include <vector>
using namespace std;


//Solution I TLE
class Solution
{
    public:
        int combinationSum4(vector<int> &nums, int target)
        {
            int res = 0;
            dfs(res, nums, target, 0);
            return res;
        }
        void dfs(int &res, vector<int> &nums, int target, int sum)
        {
            if(sum == target)
            {
                res++;
                return;
            }
            for(int i = 0; i < nums.size(); ++i)
            {
                if(sum + nums[i] <= target)
                    dfs(res, nums, target, sum+nums[i]);
            }
        }
};

//Solution II TLE
class Solution
{
    public:
        int combinationSum4(vector<int> &nums, int target)
        {
            if(target == 0)
                return 1;
            int res = 0;
            for(int i = 0; i < nums.size(); ++i)
            {
                if(target >= nums[i])
                    res += combinationSum4(nums, target-nums[i]);
            }
            return res;
        }
};

//Solution III
class Solution
{
    public:
        int combinationSum4(vector<int> &nums, int target)
        {
            vector<int> dp(target+1, -1);
            dp[0] = 1;
            return solve(dp, nums, target);
        }
        int solve(vector<int> &dp, vector<int> &nums, int target)
        {
            if(dp[target] != -1)
                return dp[target];
            int res = 0;
            for(int i = 0; i < nums.size(); ++i)
            {
                if(target >= nums[i])
                    res += solve(dp, nums, target - nums[i]);
            }
            return dp[target] = res;
        }
};

int main()
{
    return 0;
}
