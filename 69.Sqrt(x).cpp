#include <iostream>
using namespace std;

class Solution
{
    public:
        int mySqrt(int x)
        {
            if(x == 0)
                return 0;
            else if(x < 0)
                return (1<<31);
            int res;
            long long left, right, mid;
            left = 1;
            right = x>>1;
            while(left < right)
            {
                if(left * left == x)
                    return (int)left;
                if(right * right == x)
                    return (int)right;
                mid = (left + right) / 2;
                if(mid * mid == x)
                    return (int)mid;
                else if(mid * mid < x)
                    left = mid + 1;
                else
                    right = mid - 1;
            }
            return (left * left > x) ? (left - 1) : left;
        }
};

int main()
{
    Solution demo;
    int num;
    while(cin >> num)
        cout << demo.mySqrt(num) << endl;
    return 0;
}
