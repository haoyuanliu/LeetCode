#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
    public:
        int findKthLargest(vector<int> &nums, int k)
        {
            sort(nums.begin(), nums.end());
            return nums[nums.size() - k];
        }
};

class Solution
{
    public:
        int findKthLargest(vector<int> &nums, int k)
        {
            int len = nums.size();
            int res = 0;
            int left = 0;
            int right = len;
            while(left < right)
            {
                int pos = partition(nums, left, right);
                if(pos == len-k)
                {
                    res = nums[pos];
                    break;
                }
                else if(pos < len-k)
                    left = pos+1;
                else
                    right = pos;
            }
            return res;
        }
        int partition(vector<int> &nums, int begin, int end)
        {
            int pivot = nums[begin];
            while(begin < end)
            {
                while(begin < end && nums[--end] >= pivot);
                nums[begin] = nums[end];
                while(begin < end && nums[++begin] <= pivot);
                nums[end] = nums[begin];
            }
            nums[begin] = pivot;
            return begin;
        }
};

int main()
{
    return 0;
}
