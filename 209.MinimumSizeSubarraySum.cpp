#include <iostream>
#include <vector>
using namespace std;

class Solution
{
    public:
        int minSubArrayLen(int s, vector<int> &nums)
        {
            int res, count, begin, end;
            count = begin = end = 0;
            res = nums.size() + 1;
            while(end < nums.size())
            {
                count += nums[end++];
                while(count >= s)
                {
                    if(end - begin < res)
                    {
                        res = end - begin;
                    }
                    count -= nums[begin++];
                }
            }
            return res == nums.size()+1 ? 0 : res;
        }
};

int main()
{
    return 0;
}
