#include <iostream>
#include <vector>
using namespace std;

class Solution
{
    public:
        bool canJump(vector<int> &nums)
        {
            int len = nums.size();
            if(len == 1)
                return true;
            int maxJump = 0;
            for(int i = 0; i < len; ++i)
            {
                maxJump--;
                if(maxJump < nums[i])
                    maxJump = nums[i];

                if(!maxJump)
                    return false;
                if(maxJump + i >= len - 1)
                    return true;
            }
            return true;
        }
};

class Solution
{
    public:
        bool canJump(vector<int> &nums)
        {
            int len = nums.size();
            int cover = 0;
            for(int i = 0; i < len; ++i)
            {
                if(cover >= len - 1)
                    return true;
                if(cover >= i)
                    cover = max(cover, i + nums[i]);
            }
            return false;
        }
};

class Solution
{
public:
    bool canJump(vector<int>& nums)
    {
        int len = nums.size();
        int maxJump = nums[0];
        for(int i = 1; i < len; ++i)
        {
            if(maxJump == 0)
                return false;
            maxJump = max(--maxJump, nums[i]);
        }
        return true;
    }
};

int main()
{
    Solution demo;
    int temp;
    vector<int> nums;
    while(cin >> temp)
        nums.push_back(temp);
    if(demo.canJump(nums))
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}
