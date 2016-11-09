#include <iostream>
#define INT_MAX 0x7fffffff
#define INT_MIN (1<<31)
using namespace std;

class Solution
{
    public:
        int divide(int dividend, int divisor)
        {
            long long res = 0;
            int flag = 0;
            if(dividend == 0)
                return 0;
            if(divisor == 0)
                return INT_MAX;
            if((dividend < 0 && divisor > 0) || (dividend > 0 && divisor < 0))
                flag = 1;
            long long absDividend = abs((long long)dividend);
            long long absDivisor = abs((long long)divisor);
            long long left = 0;
            long long right = absDividend;
            long long temp = 0;
            long long mid = -1;
            while(left <= right)
            {
                mid = left + ((right - left)>>1);
                temp = multiplication(mid, absDivisor);
                if(temp == absDividend)
                {
                    res = mid;
                    break;
                }
                else if(temp < absDividend)
                {
                    res = mid;
                    left = mid+1;
                }
                else
                    right = mid-1;
            }
            res = flag ? -res : res;
            if(res > INT_MAX)
                return INT_MAX;
            if(res < INT_MIN)
                return INT_MIN;
            return res;
        }

        long long multiplication(long long a, long long b)
        {
            if(a == 0)
                return 0;
            long long temp = (multiplication(a>>1, b)<<1);
            if(a&1)
                temp += b;
            return temp;
        }
};

int main()
{
    Solution res;
    int a, b;
    while(cin >> a >> b)
        cout << res.divide(a, b) << endl;
    return 0;
}
