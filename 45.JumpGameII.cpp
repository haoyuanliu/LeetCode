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
                if(curJump >= i)
                    curJump = max(curJump, i + nums[i]);
            }
            return count;
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
