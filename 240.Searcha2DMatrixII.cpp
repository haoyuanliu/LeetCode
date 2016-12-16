#include <iostream>
#include <vector>
using namespace std;

class Solution
{
    public:
        bool searchMatrix(vector<vector<int> > &matrix, int target)
        {
            int m = matrix.size();
            int n = m ? matrix[0].size() : 0;
            int x = 0;
            int y = n - 1;
            while(x < m && y >= 0)
            {
                if(matrix[x][y] == target)
                    return true;
                else if(matrix[x][y] < target)
                    x++;
                else
                    y--;
            }
            return false;
        }
};

int main()
{
    return 0;
}
