#include <iostream>
#include <vector>
using namespace std;

class Solution
{
    public:
        void rotate(vector<int> &nums, int k)
        {
            int len = nums.size();
            k %= len;
            for(int i = 0; i < k; ++i)
            {
                nums.insert(nums.begin(), nums[len-1]);
                nums.pop_back();
            }
        }
};

class Solution
{
    public:
        void rotate(vector<int> &nums, int k)
        {
            int len = nums.size();
            k %= len;
            reverse(nums.begin(), nums.end());
            reverse(nums.begin(), nums.begin()+k);
            reverse(nums.begin()+k, nums.end());
        }
};

int main()
{
    return 0;
}
