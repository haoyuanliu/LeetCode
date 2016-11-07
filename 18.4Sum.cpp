#include <iostream>
#include <vector>
using namespace std;

class Solution
{
    public:
        vector<vector<int>> fourSum(vector<int>& nums, int target)
        {

        }
};

int main()
{
    Solution res;
    vector<int> num;
    int n, target;
    cin >> target;
    while(cin >> n)
        num.push_back(n);
    auto ans = res.fourSum(num);
    return 0;
}
