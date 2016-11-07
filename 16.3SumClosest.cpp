#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
    public:
        int threeSumClosest(vector<int>& nums, int target)
        {
            if(nums.size() < 3)
                return 0;
            if(nums.size() == 3)
                return nums[0]+nums[1]+nums[2];
            int res = (0x7fffffff)/2;
            sort(nums.begin(), nums.end());
            for(int i = 0; i < nums.size()-2; ++i)
            {
                int l = i+1;
                int r = nums.size()-1;
                while(l < r)
                {
                    int temp = nums[i] + nums[l] + nums[r];
                    if(l < r && temp < target)
                    {
                        if(abs(res - target) > abs(temp - target))
                            res = temp;
                        l++;
                    }
                    else if(l < r && temp > target)
                    {
                        if(abs(res - target) > abs(temp - target))
                            res = temp;
                        r--;
                    }
                    else
                        return target;
                }
            }
            return res;
        }
};

int main()
{
    Solution res;
    int n;
    int target;
    vector<int> num;
    cin >> target;
    while(cin >> n)
        num.push_back(n);
    cout << res.threeSumClosest(num, target) << endl;
    return 0;
}
