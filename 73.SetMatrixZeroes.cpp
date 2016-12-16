#include <iostream>
#include <vector>
using namespace std;

class Solution
{
    public:
        void setZeroes(vector<vector<int> > &matrix)
        {
            int m = matrix.size();
            int n = matrix[0].size();
            vector<int> row(m, 1);
            vector<int> col(n, 1);
            for(int i = 0; i < m; ++i)
            {
                for(int j = 0; j < n; ++j)
                {
                    if(matrix[i][j] == 0)
                    {
                        row[i] = 0;
                        col[j] = 0;
                    }
                }
            }
            for(int i = 0; i < m; ++i)
            {
                for(int j = 0; j < n; ++j)
                {
                    if(row[i] && col[j])
                        continue;
                    matrix[i][j] = 0;
                }
            }
        }
};

class Solution
{
    public:
        void setZeroes(vector<vector<int> > &matrix)
        {
            int m = matrix.size();
            int n = matrix[0].size();
            bool flag = false;

            for(int i = 0; i < m; ++i)
            {
                if(matrix[i][0] == 0)
                    flag = true;
                for(int j = 1; j < n; ++j)
                {
                    if(matrix[i][j] == 0)
                        matrix[i][0] = matrix[0][j] = 0;
                }
            }
            for(int i = m-1; i >= 0; --i)
            {
                for(int j = n-1; j > 0; --j)
                {
                    if(!matrix[i][0] || !matrix[0][j])
                        matrix[i][j] = 0;
                }
                if(flag)
                    matrix[i][0] = 0;
            }
        }
};

class Solution
{
    public:
        void setZeroes(vector<vector<int> > &matrix)
        {
            int m = matrix.size();
            int n = matrix[0].size();
            for(int i = 0; i < m; ++i)
            {
                for(int j = 0; j < n; ++j)
                {
                    if(matrix[i][j] == 0)
                    {
                        matrix[i][0] = 0;
                        matrix[0][j] = 0;
                    }
                }
            }
            for(int i = 1; i < m; ++i)
            {
                for(int j = 1; j < n; ++j)
                {
                    if(matrix[i][0] && matrix[0][j])
                        continue;
                    matrix[i][j] = 0;
                }
            }
        }
};

int main()
{
    return 0;
}
