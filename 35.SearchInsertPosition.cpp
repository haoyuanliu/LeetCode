#include <iostream>
#include <vector>
using namespace std;

class Solution
{
    public:
        int searchInsert(vector<int>& nums, int target)
        {
            int len = nums.size();
            for(int i = 0; i < len; ++i)
            {
                if(nums[i] == target)
                    return i;
                if(nums[i] > target)
                    return i;
            }
            return len;
        }
};

int main()
{
    Solution demo;
    int temp, target;
    vector<int> nums;
    cin >> target;
    while(cin >> temp)
        nums.push_back(temp);
    cout << demo.searchInsert(nums, target) << endl;
    return 0;
}
