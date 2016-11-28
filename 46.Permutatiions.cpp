#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
    public:
        vector<vector<int> > permute(vector<int> &nums)
        {
            vector<vector<int> > res;
            vector<int> temp;
            res.push_back(nums);
            int len = nums.size();
            if(len == 1)
            {
                return res;
            }
            int size = 1;
            for(int i = 0; i < len; ++i)
            {
                size = size * (i+1);
                temp.push_back(i+1);
            }
            size = size-1;
            int i, j;
            while(size--)
            {
                i = j = len - 1;

                while(temp[i-1] >= temp[i] && i > 0)
                    i--;

                while(temp[j] <= temp[i-1])
                    j--;
                swap(temp[i-1], temp[j]);
                swap(nums[i-1], nums[j]);

                j = len - 1;
                while(i < j)
                {
                    swap(temp[i], temp[j]);
                    swap(nums[i++], nums[j--]);
                }

                res.push_back(nums);
            }
            return res;
        }
};

int main()
{
    Solution demo;
    vector<int> nums;
    int temp;
    while(cin >> temp)
        nums.push_back(temp);
    auto ans = demo.permute(nums);
    for(const auto x : ans)
    {
        for(const auto y : x)
            cout << y << " ";
        cout << endl;
    }
    return 0;
}
