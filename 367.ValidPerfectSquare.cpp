#include <iostream>
using namespace std;

class Solution
{
    public:
        bool isPerfectSquare(int num)
        {
            if(num == 1)
                return true;
            long long left, right, mid;
            left = 1;
            right = num>>1;
            while(left < right)
            {
                if(left * left == num)
                    return true;
                if(right * right == num)
                    return true;
                mid = (left + right) / 2;
                if(mid * mid == num)
                    return true;
                else if(mid * mid < num)
                    left = mid+1;
                else
                    right = mid - 1;
            }
            return false;
        }
};

int main()
{
    return 0;
}
