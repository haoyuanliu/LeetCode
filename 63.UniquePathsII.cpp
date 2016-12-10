#include <iostream>
#include <vector>
using namespace std;

class Solution
{
    public:
        int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid)
        {
            int m = obstacleGrid.size();
            int n = obstacleGrid[0].size();
            if(obstacleGrid[0][0] == 1 || obstacleGrid[m-1][n-1] == 1)
                return 0;
            int res[2][101] = {0};
            for(int i = 1; i <= n; ++i)
            {
                if(obstacleGrid[0][i-1])
                    break;
                res[0][i] = res[1][i] = 1;
            }

            for(int i = 2; i <= m; ++i)
            {
                for(int j = 1; j <= n; ++j)
                {
                    if(obstacleGrid[i-1][j-1] == 0)
                        res[1][j] = res[0][j] + res[1][j-1];
                    else
                        res[1][j] = 0;
                }
                for(int k = 0; k <= n; ++k)
                    res[0][k] = res[1][k];
            }
            return res[0][n];
        }
};

int main()
{
    Solution demo;
    vector<int> temp;
    vector<vector<int> > nums;
    int num;
    for(int i = 0; i < 1; ++i)
    {
        for(int j = 0; j < 2; ++j)
        {
            cin >> num;
            temp.push_back(num);
        }
        nums.push_back(temp);
    }
    cout << demo.uniquePathsWithObstacles(nums) << endl;
    return 0;
}
