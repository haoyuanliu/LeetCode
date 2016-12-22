#include <iostream>
#include <vector>
using namespace std;

class Solution
{
    public:
        vector<vector<int> > combinationSum3(int k, int n)
        {
            vector<vector<int> > res;
            vector<int> temp;
            dfs(res, temp, k, n, 1, 0, 0);
            return res;
        }
        void dfs(vector<vector<int> > &res, vector<int> &temp, int k, int n, int cur, int count, int sum)
        {
            if(count == k)
            {
                if(sum == n)
                {
                    res.push_back(temp);
                    return;
                }
                else
                    return;
            }

            if(cur > 9)
                return;

            for(int i = cur; i < 10; ++i)
            {
                temp.push_back(i);
                dfs(res, temp, k, n, i+1, count+1, sum+i);
                temp.erase(temp.end()-1);
            }
        }
};

int main()
{
    return 0;
}
