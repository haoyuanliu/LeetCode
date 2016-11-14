#include <iostream>
#include <vector>
using namespace std;

class Solution
{
    public:
        int search(vector<int> &nums, int target)
        {

        }
};

int main()
{
    Solution demo;
    int target;
    int temp;
    vector<int> nums;
    cin >> target;
    while(cin >> temp)
        nums.push_back(temp);
    cout << demo.search(nums, target) << endl;
    return 0;
}
