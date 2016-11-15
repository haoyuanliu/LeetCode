#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

class Solution
{
    public:
        bool isValidSudoku(vector<vector<char> >& board)
        {
            int used[10];
            if(board.size() != 9 || board[0].size() != 9)
                return false;
            for(int i = 0; i < 9; ++i)
            {
                memset(used, 0, sizeof(used));
                for(int j = 0; j < 9; ++j)
                {
                    if(board[i][j] == '.')
                        continue;
                    if(board[i][j] <= '0' || board[i][j] > '9')
                        return false;
                    if(used[board[i][j] - '0'])
                        return false;
                    used[board[i][j] - '0'] = 1;
                }
            }
            for(int j = 0; j < 9; ++j)
            {
                memset(used, 0, sizeof(used));
                for(int i = 0; i < 9; ++i)
                {
                    if(board[i][j] == '.')
                        continue;
                    if(used[board[i][j] - '0'])
                        return false;
                    used[board[i][j] - '0'] = 1;
                }
            }
            for(int i = 0; i < 9; i += 3)
            {
                for(int j = 0; j < 9; j += 3)
                {
                    memset(used, 0, sizeof(used));
                    for(int k = i; k < i+3; ++k)
                    {
                        for(int l = j; l < j+3; ++l)
                        {
                            if(board[k][l] == '.')
                                continue;
                            if(used[board[k][l] - '0'])
                                return false;
                            used[board[k][l] - '0'] = 1;
                        }
                    }
                }
            }
            return true;
        }
};

int main()
{
    return 0;
}
