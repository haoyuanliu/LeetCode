#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
using namespace std;

class Solution
{
    public:
        int totalNQueens(int n)
        {
            int count = 0;
            int x[n];
            memset(x, 0, sizeof(x));
            put_queen(count, x, 0, n);
            return count;
        }
        void put_queen(int &count, int* x, int k, int n)
        {
            if(k >= n)
                count++;
            else
            {
                for(int i = 0; i < n; ++i)
                {
                    x[k] = i;
                    if(place(x, k))
                        put_queen(count, x, k+1, n);
                }
            }
        }
        bool place(int* x, int k)
        {
            for(int i = 0; i < k; ++i)
            {
                if(abs(x[k] - x[i]) == abs(i - k) || x[k] == x[i])
                    return false;
            }
            return true;
        }
};

int main()
{
    Solution demo;
    int num;
    while(cin >> num)
        cout << demo.totalNQueens(num) << endl;
    return 0;
}
