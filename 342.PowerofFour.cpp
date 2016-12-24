#include <iostream>
using namespace std;

class Solution
{
    public:
        bool isPowerOfFour(int num)
        {
            int temp = 1;
            if(num == 0 || num < 0)
                return false;
            for(int i = 0; i < 16; ++i)
            {
                if((num&temp) == num)
                    return true;
                temp <<= 2;
            }
            return false;
        }
};

int main()
{
    return 0;
}
