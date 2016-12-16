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
            if(target < matrix[0][0] || target > matrix[m-1][n-1])
                return false;
            int row = 0;
            while(matrix[row][0] <= target && row < m)
            {
                if(matrix[row][0] == target)
                    return true;
                row++;
            }
            row = row - 1;
            int left = 0;
            int right = n - 1;
            while(left < right)
            {
                if(matrix[row][left] == target || matrix[row][right] == target)
                    return true;
                int mid = (left + right) / 2;
                if(matrix[row][mid] == target)
                    return true;
                else if(matrix[row][mid] < target)
                    left = mid + 1;
                else
                    right = mid - 1;
            }
            return false;
        }
};

class Solution
{
    public:
        bool searchMatrix(vector<vector<int> > &matrix, int target)
        {
            if(matrix[0][0] == target)
                return true;
            int m = matrix.size();
            int n = m ? matrix[0].size() : 0;
            int total = n * m;
            int left = 0;
            int right = n * m - 1;
            int mid = 0;
            while(left < right)
            {
                if(matrix[left/n][left%n] == target)
                    return true;
                if(matrix[right/n][right%n] == target)
                    return true;
                mid = (left + right) / 2;
                if(matrix[mid/n][mid%n] == target)
                    return true;
                else if(matrix[mid/n][mid%n] < target)
                    left = mid + 1;
                else
                    right = mid - 1;
            }
            return false;
        }
};

int main()
{
    return 0;
}
