#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution
{
    public:
        string addBinary(string a, string b)
        {
            int m = a.size();
            int n = b.size();
            reverse(a.begin(), a.end());
            reverse(b.begin(), b.end());
            int carry = 0;
            string res = "";
            int x, y;
            for(int i = 0; i < max(m, n); ++i)
            {
                if(i >= m)
                    x = 0;
                else
                    x = a[i] - '0';
                if(i >= n)
                    y = 0;
                else
                    y = b[i] - '0';
                res += ((x + y + carry) % 2 + '0');
                carry = (x + y + carry) / 2;
            }
            if(carry)
                res += '1';
            reverse(res.begin(), res.end());
            return res;
        }
};

int main()
{
    Solution demo;
    string s1, s2;
    while(cin >> s1 >> s2)
        cout << demo.addBinary(s1, s2) << endl;
    return 0;
}
