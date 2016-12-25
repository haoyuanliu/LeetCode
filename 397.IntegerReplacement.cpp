#include <iostream>
using namespace std;

//Solution I TLE
class Solution
{
    public:
        int integerReplacement(int n)
        {
            if(n == 2)
                return 1;
            if(n % 2)
                return 1 + min(integerReplacement(n+1), integerReplacement(n-1));
            else
                return integerReplacement(n / 2) + 1;
        }
};

class Solution
{
    public:
        int integerReplacement(int n)
        {
            if(n == 0x7fffffff)
                return 32;
            int count = 0;
            while(n > 1)
            {
                count++;
                if(n & 1)
                {
                    if(n == 3 || (n&2) == 0)
                        n--;
                    else
                        n++;
                }
                else
                    n >>= 1;
            }
            return count;
        }
};

int main()
{
    return 0;
}
