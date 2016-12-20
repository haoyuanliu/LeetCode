#include <iostream>
#include <vector>
using namespace std;

class Solution
{
    public:
        vector<vector<int> > combine(int n, int k)
        {
            vector<vector<int> > res;
            vector<int> temp;
            pushBack(res, temp, 1, k, n, 0);
            return res;
        }

        void pushBack(vector<vector<int> > &res, vector<int> &temp, int next, int k, int n, int count)
        {
            if(count == k)
                res.push_back(temp);
            for(int i = next; i <= n; ++i)
            {
                temp.push_back(i);
                pushBack(res, temp, i+1, k, n, count+1);
                temp.erase(temp.end()-1);
            }
        }
};

int main()
{
    Solution demo;
    int n, k;
    cin >> n >> k;
    auto res = demo.combine(n, k);
    for(auto x : res)
    {
        for(auto y : x)
            cout << y << " ";
        cout << endl;
    }
    return 0;
}
