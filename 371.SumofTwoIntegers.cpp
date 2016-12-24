#include <iostream>
using namespace std;

class Solution
{
    public:
        int getSum(int a, int b)
        {
            int carry = a&b;
            int res = a ^ b;
            int temp;
            while(carry)
            {
                carry <<= 1;
                temp = res & carry;
                res = res ^ carry;
                carry = temp;
            }
            return res;
        }
};

int main()
{
    return 0;
}
