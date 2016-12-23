#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
    public:
        int singleNumber(vector<int> &nums)
        {
            int res = nums[0];
            sort(nums.begin(), nums.end());
            for(int i  = 0; i < nums.size(); ++i)
            {
                if(i+1 == nums.size())
                {
                    res = nums[i];
                    break;
                }
                if(nums[i] == nums[i+1])
                    i++;
                else
                {
                    res = nums[i];
                    break;
                }
            }
            return res;
        }
};

int main()
{
    return 0;
}
