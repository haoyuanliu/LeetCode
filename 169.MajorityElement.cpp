#include <iostream>
#include <vector>
using namespace std;

class Solution
{
    public:
        int majorityElement(vector<int> &nums)
        {
            int res = nums[0];
            int count = 1;
            for(int i = 1; i < nums.size(); ++i)
            {
                if(count == 0)
                {
                    count++;
                    res = nums[i];
                }
                else if(nums[i] == res)
                    count++;
                else
                    count--;
            }
            return res;
        }
};

int main()
{
    return 0;
}
