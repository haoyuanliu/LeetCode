#include <iostream>
#include <vector>
using namespace std;

class Solution
{
    public:
        vector<int> countBits(int num)
        {
            vector<int> res(num+1, 0);
            int start = 0;
            int end = 0;
            for(int i = 1; i < num+1; ++i)
            {
                if(start > end)
                {
                    start = 0;
                    end = i-1;
                }
                res[i] = res[start++] + 1;
            }
            return res;
        }
};

int main()
{
    return 0;
}
