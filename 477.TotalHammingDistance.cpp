#include <iostream>
#include <vector>
using namespace std;

class Solution
{
    public:
        int totalHammingDistance(vector<int> &nums)
        {
            int res = 0;
            int len = nums.size();
            int count = 0;
            for(int i = 0; i < 32; ++i)
            {
                count = 0;
                for(int j = 0; j < nums.size(); ++j)
                {
                    if((nums[j]>>i)&1)
                        count++;
                }
                res += (len - count) * count;
            }
            return res;
        }
};

int main()
{
    return 0;
}
