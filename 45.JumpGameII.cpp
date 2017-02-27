#include <iostream>
#include <vector>
using namespace std;

class Solution
{
    public:
        int jump(vector<int> &nums)
        {
            int len = nums.size();
            int curJump = 0;
            int lastJump = 0;
            int count = 0;
            for(int i = 0; i < len; ++i)
            {
                if(lastJump < i)
                {
                    count++;
                    lastJump = curJump;
                }
                if(lastJump >= len-1)
                    return count;
                if(curJump >= i)
                    curJump = max(curJump, i + nums[i]);
            }
            return count;
        }
};

class Solution
{
public:
    int jump(vector<int>& nums)
    {
        int res = 0;
        int len = nums.size();
        int start = 0;
        int cover = 0;
        int temp;
        while(cover < len - 1)
        {
            temp = cover;
            for(int i = start; i <= temp; ++i)
            {
                if(i+nums[i] > cover)
                {
                    start = i+1;
                    cover = i+nums[i];
                }
            }
            res++;
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
    cout << demo.jump(nums) << endl;
    return 0;
}
