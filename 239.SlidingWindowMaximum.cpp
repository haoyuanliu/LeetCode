#include <iostream>
#include <vector>
#include <deque>
using namespace std;

class Solution
{
    public:
        vector<int> maxSlidingWindow(vector<int>& nums, int k)
        {
            if(k == 0)
                return nums;
            int len = nums.size();
            vector<int> temp = nums;
            for(int i = 1; i < k; ++i)
            {
                for(int j = i; j < len; ++j)
                {
                    temp[j] = max(nums[j-i], temp[j]);
                }
            }
            vector<int> res;
            for(int i = k-1; i < len; ++i)
                res.push_back(temp[i]);
            return res;
        }
};

class Solution
{
    public:
        vector<int> maxSlidingWindow(vector<int>& nums, int k)
        {
            vector<int> res;
            if(k == 0)
                return res;
            deque<int> temp;
            for(int i = 0; i < nums.size(); ++i)
            {
                while(!temp.empty() && temp.front() < i-k+1)
                    temp.pop_front();
                while(!temp.empty() && nums[temp.back()] < nums[i])
                    temp.pop_back();
                temp.push_back(i);
                if(i >= k - 1)
                    res.push_back(nums[temp.front()]);
            }
            return res;
        }
};

int main()
{
    return 0;
}
