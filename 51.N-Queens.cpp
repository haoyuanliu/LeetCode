#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution
{
    public:
        int x[100] = {0};
        vector<vector<string> > solveNQueens(int n)
        {
            vector<vector<string> > res;
            put_queen(res, 0, n);
            return res;
        }
        void put_queen(vector<vector<string> > &res, int k, int n)
        {
            if(k >= n)
            {
                vector<string> str;
                for(int i = 0; i < n; ++i)
                {
                    string temp(n, '.');
                    temp[x[i]] = 'Q';
                    str.push_back(temp);
                }
                res.push_back(str);
            }
            else
            {
                for(int i = 0; i < n; ++i)
                {
                    x[k] = i;
                    if(place(k))
                        put_queen(res, k+1, n);
                    x[k] = 0;
                }
            }
        }
        bool place(int k)
        {
            for(int i = 0; i < k; ++i)
            {
                if(abs(x[k] - x[i]) == abs(k - i) || x[k] == x[i])
                    return false;
            }
            return true;
        }
};

int main()
{
    Solution demo;
    int n;
    while(cin >> n)
    {
        vector<vector<string> > res = demo.solveNQueens(n);
        for(const auto x : res)
        {
            for(const auto y : x)
                cout << y << endl;
            cout << endl;
            cout << endl;
        }
    }
    return 0;
}
