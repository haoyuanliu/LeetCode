#include <iostream>
#include <vector>
using namespace std;

class Solution
{
    public:
        void gameOfLife(vector<vector<int> > &board)
        {
            int m = board.size();
            int n = m ? board[0].size() : 0;
            int count;
            for(int i = 0; i < m; ++i)
            {
                for(int j = 0; j < n; ++j)
                {
                    count = board[i][j] ? -1 : 0;
                    for(int x = max(0, i-1); x < min(i+2, m); ++x)
                    {
                        for(int y = max(0, j-1); y < min(j+2, n); ++y)
                        {
                            if(board[x][y]&1)
                                count++;
                        }
                    }
                    if(count == 2)
                        board[i][j] += board[i][j]<<1;
                    else if(count == 3)
                        board[i][j] += 2;
                }
            }
            for(int i = 0; i < m ; ++i)
                for(int j = 0; j < n; ++j)
                    board[i][j] >>= 1;
        }
};

int main()
{
    return 0;
}
