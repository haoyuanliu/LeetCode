#include <iostream>
#include <vector>
using namespace std;

class Solution
{
    public:
        vector<vector<int> > subsets(vector<int> &nums)
        {
            vector<vector<int> > res;
            vector<int> temp;
            dfs(res, temp, nums, 0);
            return res;
        }
        void dfs(vector<vector<int> > &res, vector<int> &temp, vector<int> &nums, int cur)
        {
            if(cur == nums.size())
            {
                res.push_back(temp);
                return;
            }
            for(int i = cur; i < nums.size(); ++i)
            {
                temp.push_back(nums[i]);
                dfs(res, temp, nums, i+1);
                temp.erase(temp.end()-1);
            }
            res.push_back(temp);
        }
};

int main()
{
    return 0;
}
