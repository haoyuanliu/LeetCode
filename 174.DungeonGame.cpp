#include <iostream>
#include <vector>
using namespace std;

class Solution
{
    public:
        int calculateMinimumHP(vector<vector<int> > &dumgeon)
        {
            int m = dumgeon.size();
            int n = dumgeon[0].size();
            dumgeon[m-1][n-1] = max(1, 1 - dumgeon[m-1][n-1]);
            for(int j = n-2; j >= 0; --j)
            {
                dumgeon[m-1][j] = max(1, dumgeon[m-1][j+1] - dumgeon[m-1][j]);
            }
            for(int i = m-2; i >= 0; --i)
            {
                dumgeon[i][n-1] = max(1, dumgeon[i+1][n-1] - dumgeon[i][n-1]);
            }
            for(int i = m-2; i >= 0; --i)
            {
                for(int j = n-2; j >= 0; --j)
                {
                    dumgeon[i][j] = max(1, min(dumgeon[i+1][j], dumgeon[i][j+1]) - dumgeon[i][j]);
                }
            }
            return dumgeon[0][0];
        }
};

int main()
{
    Solution demo;
    vector<int> num;
    vector<vector<int> > nums;
    int temp;
    for(int i = 0; i < 1; ++i)
    {
        for(int j = 0; j < 2; ++j)
        {
            cin >> temp;
            num.push_back(temp);
        }
        nums.push_back(num);
    }
    cout << demo.calculateMinimumHP(nums) << endl;
    return 0;
}
