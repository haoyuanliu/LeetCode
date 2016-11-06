#include <iostream>
#include <vector>
using namespace std;

class Solution
{
    public:
        int maxArea(vector<int>& height)
        {
            int res = 0;
            int len = height.size();
            int l = 0;
            int r = len - 1;
            while(l < r)
            {
                res = max(res, (r-l)*min(height[l], height[r]));
                if(height[l] < height[r])
                    l++;
                else
                    r--;
            }
            return res;
        }
};

int main()
{
    vector<int> n;
    int num;
    while(cin >> num)
        n.push_back(num);
    Solution res;
    cout << res.maxArea(n) << endl;
    return 0;
}
