#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution
{
    public:
        string addStrings(string num1, string num2)
        {
            int m = num1.size();
            int n = num2.size();
            string res = "";
            reverse(num1.begin(), num1.end());
            reverse(num2.begin(), num2.end());
            int carry = 0;
            int a, b;
            for(int i = 0; i < max(m, n); ++i)
            {
                if(i >= m)
                    a = 0;
                else
                    a = num1[i] - '0';

                if(i >= n)
                    b = 0;
                else
                    b = num2[i] - '0';

                res += (a + b + carry) % 10 + '0';
                carry = (a + b + carry) / 10;
            }
            if(carry)
                res += '1';
            reverse(res.begin(), res.end());
            return res;
        }
};
