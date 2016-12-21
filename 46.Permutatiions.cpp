#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
    public:
        vector<vector<int> > permute(vector<int> &nums)
        {
            vector<vector<int> > res;
            vector<int> temp;
            int size = 1;
            int i, j;

            res.push_back(nums);
            int len = nums.size();
            if(len == 1)
                return res;

            for(int i = 0; i < len; ++i)
            {
                size = size * (i+1);
                temp.push_back(i+1);
            }
            size = size-1;
            while(size--)
            {
                i = j = len - 1;
                while(temp[i-1] >= temp[i])
                    i--;
                while(temp[j] <= temp[i-1])
                    j--;
                swap(temp[i-1], temp[j]);
                swap(nums[i-1], nums[j]);

                j = len - 1;
                while(i < j)
                {
                    swap(temp[i], temp[j]);
                    swap(nums[i++], nums[j--]);
                }

                res.push_back(nums);
            }
            return res;
        }
};

class Solution
{
    public:
        vector<vector<int> > permute(vector<int> &nums)
        {
            vector<vector<int> > res;
            dfs(res, nums, 0);
            return res;
        }
        void dfs(vector<vector<int> > &res, vector<int> &nums, int cur)
        {
            if(cur >= nums.size())
            {
                res.push_back(nums);
                return;
            }
            for(int i = cur; i < nums.size(); ++i)
            {
                swap(nums[cur], nums[i]);
                dfs(res, nums, cur+1);
                swap(nums[cur], nums[i]);
            }
        }
};


int main()
{
    Solution demo;
    vector<int> nums;
    int temp;
    while(cin >> temp)
        nums.push_back(temp);
    auto ans = demo.permute(nums);
    for(const auto x : ans)
    {
        for(const auto y : x)
            cout << y << " ";
        cout << endl;
    }
    return 0;
}
