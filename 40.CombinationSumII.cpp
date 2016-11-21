#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
    public:
        vector<vector<int> > combinationSum2(vector<int> &candidates, int target)
        {
            vector<vector<int> > res;
            vector<int> temp;
            sort(candidates.begin(), candidates.end());
            solve(res, temp, candidates, target, 0, 0, candidates.size());
            return res;
        }
        void solve(vector<vector<int> > &res, vector<int> &temp, vector<int> candidates, int target, int cur, int sum, int len)
        {
            if(sum == target)
            {
                res.push_back(temp);
                return;
            }
            for(int i = cur; i < len; ++i)
            {
                if(sum + candidates[i] <= target)
                {
                    temp.push_back(candidates[i]);
                    solve(res, temp, candidates, target, i+1, sum+candidates[i], len);
                    temp.pop_back();
                    while(i+1 < len && candidates[i] == candidates[i+1]) //如果下一个值等于当前值，则跳过，
                        i++;
                }
            }
        }
};

int main()
{
    return 0;
}
