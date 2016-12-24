#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
    public:
        vector<int> singleNumber(vector<int> &nums)
        {
            vector<int> res;
            if(nums.size() == 2)
            {
                res.push_back(nums[0]);
                res.push_back(nums[1]);
                return res;
            }
            sort(nums.begin(), nums.end());
            for(int i = 0; i < nums.size(); i++)
            {
                if(nums[i] == nums[i+1])
                    i++;
                else
                    res.push_back(nums[i]);
            }
            return res;
        }
};

int main()
{
    return 0;
}
