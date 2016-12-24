#include <iostream>
#include <vector>
using namespace std;

class Solution
{
    public:
        int maxProduct(vector<string> &words)
        {
            int res = 0;
            int len = words.size();
            vector<int> nums(len, 0);
            for(int i = 0; i < len; ++i)
            {
                for(int j = 0; j < words[i].size(); ++j)
                {
                    nums[i] |= 1<<(words[i][j] - 'a');
                }
            }
            for(int i = 0; i < len; ++i)
            {
                for(int j = i+1; j < len; ++j)
                {
                    if(nums[i] & nums[j])
                        continue;
                    else
                        res = max(res, int(words[i].size() * words[j].size()));
                }
            }
            return res;
        }
};

int main()
{
    return 0;
}
