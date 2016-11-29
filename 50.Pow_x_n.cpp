#include <iostream>
#include <stdio.h>
using namespace std;

class Solution
{
    public:
        double myPow(double x, int n)
        {
            double res = 1;
            long long newn = n;
            if(newn < 0)
            {
                newn = -newn;
                x = 1.0 / x;
            }
            while(newn > 0)
            {
                if(newn&1)
                    res = res * x;
                x = x * x;
                newn = newn>>1;
            }
            return res;
        }
};

int main()
{
    Solution demo;
    double num;
    int n;
    while(cin >> num >> n)
        printf("%.5f\n", demo.myPow(num, n));
    return 0;
}
