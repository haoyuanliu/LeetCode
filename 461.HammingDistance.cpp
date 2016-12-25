#include <iostream>
using namespace std;

class Solution
{
    public:
        int hammingDistance(int x, int y)
        {
            int res = 0;
            int temp = x^y;
            while(temp)
            {
                temp = temp&(temp-1);
                res++;
            }
            return res;
        }
};
