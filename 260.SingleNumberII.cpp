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

class Solution
{
    public:
        vector<int> singleNumber(vector<int> &nums)
        {
            vector<int> res(2, 0);
            int temp = 0;
            for(int i = 0; i < nums.size(); ++i)
                temp ^= nums[i];
            temp &= -temp;
            for(int i = 0; i < nums.size(); ++i)
            {
                if(temp & nums[i])
                    res[0] ^= nums[i];
                else
                    res[1] ^= nums[i];
            }
            return res;
        }
};

int main()
{
    return 0;
}
