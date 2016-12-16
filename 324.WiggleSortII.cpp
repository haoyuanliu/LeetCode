#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
    public:
        void wiggleSort(vector<int> &nums)
        {
            int len = nums.size();
            vector<int> temp(len, 0);
            sort(nums.begin(), nums.end());
            int mid = (len + 1) >> 1;
            int right = len;
            for(int i = 0; i < len; ++i)
                temp[i] = (i&1) ? nums[--right] : nums[--mid];
            for(int i = 0; i < len; ++i)
                nums[i] = temp[i];
        }
};

int main()
{
    return 0;
}
