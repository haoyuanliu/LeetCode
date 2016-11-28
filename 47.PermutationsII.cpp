#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
    public:
        vector<vector<int> > permuteUnique(vector<int> & nums)
        {
            vector<vector<int> > res;
            sort(nums.begin(), nums.end());
            res.push_back(nums);
            int len = nums.size();
            int i, j;
            if(len == 1)
                return res;
            while(1)
            {
                i = j = len - 1;
                while(nums[i] <= nums[i-1] && i >= 0)
                    i--;
                if(i == -1 || i == 0)
                    break;
                while(nums[j] <= nums[i-1])
                    j--;
                swap(nums[i-1], nums[j]);
                j = len - 1;
                while(i < j)
                    swap(nums[i++], nums[j--]);
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
    vector<vector<int> > res;
    res = demo.permuteUnique(nums);
    for(const auto x : res)
    {
        for(const auto y : x)
            cout << y << " ";
        cout << endl;
    }
    return 0;
}
