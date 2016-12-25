#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

class Solution
{
    public:
        int findMaximumXOR(vector<int> &nums)
        {
            int res = 0;
            unordered_set<int> pre;
            for(int i = 31; i >= 0; --i)
            {
                res <<= 1;
                pre.clear();
                for(auto const num : nums)
                    pre.insert(num>>i);
                for(auto const p : pre)
                {
                    if(pre.find((res^1)^p) != pre.end())
                    {
                        res++;
                        break;
                    }
                }
            }
            return res;
        }
};

int main()
{
    return 0;
}
