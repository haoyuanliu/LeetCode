#include <iostream>
#include <vector>
using namespace std;

class Solution
{
    public:
        vector<vector<int> > generateMatrix(int n)
        {
            vector<vector<int> > res(n, vector<int>(n, 0));
            int tot = n * n;
            int count = 1;
            for(int i = 0; i <= n/2; ++i)
            {
                if(count > tot)
                    break;
                for(int j = i; j < n-i && count <= tot; ++j)
                    res[i][j] = count++;
                for(int j = i+1; j < n-i-1 && count <= tot; ++j)
                    res[j][n-i-1] = count++;
                for(int j = n-i-1; j >= i && count <= tot; --j)
                    res[n-i-1][j] = count++;
                for(int j = n-i-2; j > i && count <= tot; --j)
                    res[j][i] = count++;
            }
            return res;
        }
};

int main()
{
    Solution demo;
    int size;
    cin >> size;
    auto res = demo.generateMatrix(size);
    for(const auto x : res)
    {
        for(const auto y : x)
            cout << y << " ";
        cout << endl;
    }
    return 0;
}
