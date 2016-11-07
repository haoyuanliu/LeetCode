#include <iostream>
#include <vector>
using namespace std;

class Solution
{
    public:
        int threeSumClosest(vector<int>& nums, int target)
        {

        }
};

int main()
{
    Solution res;
    int n;
    int target;
    vector<int> num;
    cin >> target;
    while(cin >> n)
        num.push_back(n);
    cout << res.threeSumClosest(num, target) << endl;
    return 0;
}
