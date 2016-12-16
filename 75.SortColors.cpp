#include <iostream>
#include <vector>
using namespace std;

class Solution
{
    public:
        void sortColors(vector<int> &nums)
        {
            int len = nums.size();
            int left = 0;
            int right = len - 1;
            for(int i = 0; i < len; ++i)
            {
                if(i > right)
                    break;
                if(nums[i] == 1)
                    continue;
                else if(nums[i] == 0)
                {
                    swap(nums[i], nums[left]);
                    left++;
                }
                else
                {
                    swap(nums[i], nums[right]);
                    right--;
                    i--;
                }
            }
        }
};

int main()
{
    return 0;
}
