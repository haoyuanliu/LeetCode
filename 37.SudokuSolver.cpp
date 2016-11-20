#include <iostream>
#include <vector>
using namespace std;

class Solution
{
    public:
        void solveSudoku(vector<vector<char> > & board)
        {
            solve(0, board);
        }

        bool check(int x, int y, vector<vector<char> > &board)
        {
            for(int i = 0; i < 9; ++i)
                if((i!=x && board[i][y]==board[x][y]) || (i!=y && board[x][i]==board[x][y]))
                    return false;
            for(int i = 0; i < 3; ++i)
                for(int j = 0; j < 3; ++j)
                    if(board[x/3*3+i][y/3*3+j]==board[x][y] && (x/3*3+i!=x || y/3*3+j!=y))
                        return false;
            return true;
        }
        bool solve(int cur, vector<vector<char> > &board)
        {
            if(cur == 81)
                return true;
            int i = cur / 9;
            int j = cur % 9;
            if(board[i][j] != '.')
                return solve(cur+1, board);
            for(int k = 1; k <= 9; ++k)
            {
                board[i][j] = k + '0';
                if(check(i, j, board) && solve(cur+1, board))
                    return true;
                board[i][j] = '.';
            }
            return false;
        }
};

int main()
{
    return 0;
}
