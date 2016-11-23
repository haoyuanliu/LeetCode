#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

class Solution
{
    public:
        int firstMissingPositive(vector<int>& nums)
        {
            int res = 1;
            sort(nums.begin(), nums.end());
            for(int i = 0; i < nums.size(); ++i)
            {
                if(nums[i] <= 0)
                    continue;
                if(nums[i] == res-1)
                    continue;
                if(nums[i] == res)
                    res = nums[i]+1;
                else
                    return res;
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
    {
        nums.push_back(temp);
    }
    cout << demo.firstMissingPositive(nums) << endl;
    return 0;
}
