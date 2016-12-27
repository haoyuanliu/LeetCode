#include <iostream>
#include <vector>
using namespace std;

class Solution
{
    public:
        int maxCoins(vector<int> &nums)
        {
            int res = 0;
            int len = nums.size();
            vector<int> temp = nums;
            temp.insert(temp.begin(), 1);
            temp.push_back(1);
            dfs(res, nums.size(), temp, nums, 0);
            return res;
        }
        void dfs(int &res, int count, vector<int> &temp, vector<int> nums, int sum)
        {
            if(count == 0)
            {
                res = max(res, sum);
                return;
            }
            int l, r;
            for(int i = 1; i <= nums.size(); ++i)
            {
                if(temp[i])
                {
                    temp[i] = 0;
                    l = i-1;
                    r = i+1;
                    while(!temp[l]) l--;
                    while(!temp[r]) r++;
                    dfs(res, count-1, temp, nums, sum + temp[l]*nums[i-1]*temp[r]);
                    temp[i] = nums[i-1];
                }
            }
        }
};

class Solution
{
    public:
        int maxCoins(vector<int> &nums)
        {
            int len = nums.size();
            nums.insert(nums.begin(), 1);
            nums.insert(nums.end(), 1);
            vector<vector<int>> dp(len+2, vector<int>(len+2, 0));
            for(int k = 1; k <= len; ++k)
            {
                for(int i = 1; i <= len-k+1; ++i)
                {
                        for(int j = i; j < i+k; ++j)
                        {
                            dp[i][i+k-1] = max(dp[i][i+k-1], dp[i][j-1] + nums[i-1]*nums[j]*nums[i+k] + dp[j+1][i+k-1]); 
                        }
                }
            }
            return dp[1][len];
        }
};

int main()
{
    Solution demo;
    vector<int> nums;
    int num;
    while(cin >> num)
    {
        nums.push_back(num);
    }
    cout << demo.maxCoins(nums) << endl;
    return 0;
}
