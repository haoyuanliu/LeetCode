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
                if(*it == *(it+1) && it+1 != candidates.end())
                    it = candidates.erase(it);
            }
        }
};

int main()
{
    Solution demo;
    return 0;
}
