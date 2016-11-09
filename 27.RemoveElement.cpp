#include <iostream>
#include <vector>
using namespace std;

class Solution
{
    public:
        int removeElement(vector<int> &nums, int val)
        {
            for(auto it = nums.begin(); it != nums.end();)
            {
                if(*it == val)
                    it = nums.erase(it);
                else
                    it++;
            }
            return nums.size();
        }
};

int main()
{
    Solution res;
    int temp, val;
    vector<int> nums;
    cin >> val;
    while(cin >> temp)
        nums.push_back(temp);
    cout << res.removeElement(nums, val) << endl;
    return 0;
}
