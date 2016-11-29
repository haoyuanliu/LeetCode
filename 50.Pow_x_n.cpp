#include <iostream>
#include <stdio.h>
using namespace std;

class Solution
{
    public:
        double myPow(double x, int n)
        {
            double res= 1;
            if(n < 0)
            {
                n = - n;
                x = 1 / x;
            }
            while(n)
            {
                if(n&1)
                    res = res * x;
                x = x * x;
                n = n>>1;
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
