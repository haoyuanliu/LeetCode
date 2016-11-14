#include <iostream>
#include <vector>
using namespace std;

class Solution
{
    public:
        vector<int> searchRange(vector<int>& nums, int target)
        {
            int len = nums.size();
            int start, end;
            vector<int> res;
            if(target < nums[0] || target > nums[len-1])
                start = end = -1;
            for(int i = 0; i < len; ++i)
            {
                if(nums[i] == target)
                {
                    start = end = i;
                    while(nums[++i] == target && i < len)
                        end = i;
                    break;
                }
                if(nums[i] > target)
                {
                    start = end = -1;
                    break;
                }
            }
            res.push_back(start);
            res.push_back(end);
            return res;
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
    vector<int> res = demo.searchRange(nums, target);
    for(const auto x : res)
        cout << x << " ";
    cout << endl;
    return 0;
}
