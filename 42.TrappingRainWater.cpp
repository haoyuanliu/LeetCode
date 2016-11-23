#include <iostream>
#include <vector>
using namespace std;

class Solution
{
    public:
        int trap(vector<int> &height)
        {
            int res = 0;
            int len = height.size();
            int l = 0;
            int r = len-1;
            int secondHeight = 0;
            while(l < r)
            {
                if(height[l] < height[r])
                {
                    if(secondHeight < height[l])
                        secondHeight = height[l];
                    else
                        res += secondHeight - height[l];
                    l++;
                }
                else
                {
                    if(secondHeight < height[r])
                        secondHeight = height[r];
                    else
                        res += secondHeight - height[r];
                    r--;
                }
            }
            return res;
        }
};

int main()
{
    Solution demo;
    int temp;
    vector<int> nums;
    while(cin >> temp)
        nums.push_back(temp);
    cout << demo.trap(nums) << endl;
    return 0;
}
