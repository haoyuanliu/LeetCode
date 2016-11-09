#include <iostream>
#include <vector>
using namespace std;

class Solution
{
    public:
        int removeDuplicates(vector<int> &nums)
        {
            if(nums.size() == 0)
                return 0;
            int pre, count;
            bool start = true;
            count = 0;
            vector<int>::iterator it;
            for(it = nums.begin(); it != nums.end();)
            {
                if(start)
                {
                    pre = *it;
                    count++;
                    start = false;
                    it++;
                }
                else
                {
                    if(pre == *it)
                        it = nums.erase(it);
                    else
                    {
                        count++;
                        pre = *it;
                        it++;
                    }
                }
            }
            return count;
        }
};

int main()
{
    int n, len;
    Solution res;
    vector<int> nums;
    cin >> len;
    for(int i = 0; i < len; ++i)
    {
        cin >> n;
        nums.push_back(n);
    }
    cout << res.removeDuplicates(nums) << endl;
    return 0;
}
