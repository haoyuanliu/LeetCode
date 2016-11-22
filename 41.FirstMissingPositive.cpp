#include <iostream>
#include <vector>
using namespace std;

class Solution
{
    public:
        int firstMissingPositive(vector<int>& nums)
        {

        }
};

int main()
{
    Solution demo;
    int temp;
    vector<int> nums;
    while(cin >> temp)
    {
        nums.push_back(temp);
    }
    cout << demo.firstMissingPositive(nums) << endl;
    return 0;
}
