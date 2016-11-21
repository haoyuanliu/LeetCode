#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

class Solution
{
    public:
        vector<vector<int> > combinationSum(vector<int>& candidates, int target)
        {
            vector<vector<int> > res;
            vector<int> temp;
            vector<int>::iterator it;
            sort(candidates.begin(), candidates.end());
            for(it = candidates.begin(); it != candidates.end(); ++it)
            {
                while(*it == *(it+1) && it+1 != candidates.end())
                    it = candidates.erase(it);
            }
            solve(temp, candidates, res, target, 0, candidates.size(), 0);
            return res;
        }
        void solve(vector<int> &temp, vector<int> candidates, vector<vector<int> > &res, int target, int cur, int len, int sum)
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
                    solve(temp, candidates, res, target, i, len, sum + candidates[i]);
                    temp.pop_back();
                }
            }
        }
};

int main()
{
    Solution demo;
    return 0;
}
