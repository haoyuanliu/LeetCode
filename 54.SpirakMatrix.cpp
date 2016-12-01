#include <iostream>
#include <vector>
using namespace std;

class Solution
{
    public:
        vector<int> spiralOrder(vector<vector<int> > &matrix)
        {
            vector<int> res;
            if(matrix.size() == 0)
                return res;
            int m = matrix.size();
            int n = matrix[0].size();
            int tot = m * n;
            int count = 0;
            int max = (m>>1) + 1;
            for(int k = 0; k < max; ++k)
            {
                for(int i = k; i < n-k && count < tot; ++i, ++count)
                    res.push_back(matrix[k][i]);
                for(int i = k+1; i < m-k-1 && count < tot; ++i, ++count)
                    res.push_back(matrix[i][n-k-1]);
                for(int i = n-k-1; i >= k && count < tot; --i, ++count)
                    res.push_back(matrix[m-k-1][i]);
                for(int i = m-k-2; i > k && count < tot; --i, ++count)
                    res.push_back(matrix[i][k]);
            }
            return res;
        }
};

int main()
{
    return 0;
}
