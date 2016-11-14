#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
    public:
        int search(vector<int> &nums, int target)
        {
            int len = nums.size();
            if(target <= nums[len-1])
            {
                for(int i = len-1; i >= 0; --i)
                {
                    if(target == nums[i])
                        return i;
                    if(nums[i] > nums[len-1])
                        break;
                }
            }
            else if(target > nums[len-1] && target < nums[0])
                return -1;
            else
            {
                for(int i = 0; i < len; ++i)
                {
                    if(target == nums[i])
                        return i;
                    if(nums[i] < nums[0])
                        break;
                }
            }
            return -1;
        }
};

int main()
{
    Solution demo;
    int target;
    int temp;
    vector<int> nums;
    cin >> target;
    while(cin >> temp)
        nums.push_back(temp);
    cout << demo.search(nums, target) << endl;
    return 0;
}
