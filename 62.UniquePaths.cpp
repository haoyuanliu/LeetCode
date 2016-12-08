#include <iostream>
using namespace std;

//TLE
/*class Solution
{
    public:
        int count = 0;
        int uniquePaths(int m, int n)
        {
            step(1, 1, m, n);
            return count;
        }

        void step(int x, int y, int m, int n)
        {
            if(x > m || y > n)
                return;
            if(x == m && y == n)
            {
                count++;
                return;
            }
            step(x+1, y, m, n);
            step(x, y+1, m, n);
        }
};*/

class Solution
{
    public:
        int uniquePaths(int m, int n)
        {
            int res[m+1][n+1];
            for(int i = 0; i <= m; ++i)
                for(int j = 0; j <= n; ++j)
                    res[i][j] = 0;
            for(int i = 1; i <= m; ++i)
                res[i][1] = 1;
            for(int j = 1; j <= n; ++j)
                res[1][j] = 1;
            for(int i = 2; i <= m; ++i)
            {
                for(int j = 2; j <= n; ++j)
                {
                    res[i][j] = res[i-1][j] + res[i][j-1];
                }
            }
            return res[m][n];
        }
};

int main()
{
    Solution demo;
    int m, n;
    while(cin >> m >> n)
        cout << demo.uniquePaths(m, n) << endl;
    return 0;
}
