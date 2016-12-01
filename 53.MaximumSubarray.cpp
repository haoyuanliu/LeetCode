#include <iostream>
#include <vector>
using namespace std;

class Solution
{
    public:
        int maxSubArray(vector<int> &nums)
        {
            int res = (1<<31);
            int sum = 0;
            for(int i = 0; i < nums.size(); ++i)
            {
                if(sum < 0)
                    sum = nums[i];
                else
                    sum += nums[i];
                res = max(sum, res);
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
    cout << demo.maxSubArray(nums) << endl;
    return 0;
}
