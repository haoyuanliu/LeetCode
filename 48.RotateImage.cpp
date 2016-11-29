#include <iostream>
#include <vector>
using namespace std;

class Solution
{
    public:
        void rotate(vector<vector<int> > &matrix)
        {
            int row = matrix.size();
            int col = matrix[0].size();
            vector<vector<int> > res;
            vector<int> temp;
            for(int i = 0; i < col; ++i)
            {
                temp.clear();
                for(int j = row-1; j >= 0; --j)
                {
                    temp.push_back(matrix[j][i]);
                }
                res.push_back(temp);
            }
            matrix = res;
        }
};

class Solution
{
    public:
        void rotate(vector<vector<int> > &matrix)
        {
            int size = matrix.size();
            for(int i = 0; i < size; ++i)
                for(int j = 0; j < size - i; ++j)
                    swap(matrix[i][j], matrix[size-1-i][size-1-j]);
            reverse(matrix.begin(), matrix.end());
        }
};

class Solution
{
    public:
        void rotate(vector<vector<int> > &matrix)
        {
            int len = matrix.size();
            for(int i = 0; i < len; ++i)
            {
                for(int j = 0; j < i; ++j)
                {
                    swap(matrix[i][j], matrix[j][i]);
                }
            }
            for(int i = 0; i < len; ++i)
                reverse(matrix[i].begin(), matrix[i].end());
        }
};

int main()
{
    return 0;
}
