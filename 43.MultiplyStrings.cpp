#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
    public:
        string multiply(string num1, string num2)
        {
            int m = num1.size();
            int n = num2.size();
            if(num1 == "0" || num2 == "0")
                return "0";
            reverse(num1.begin(), num1.end());
            reverse(num2.begin(), num2.end());
            vector<int> res(m+n, 0);
            for(int i = 0; i < m; ++i)
                for(int j = 0, id = i; j < n; ++j)
                    res[id++] += (num1[i] - '0') * (num2[j] - '0');
            int carry = 0;
            for(int i = 0; i < m+n; ++i)
            {
                int temp = res[i];
                res[i] = (temp + carry) % 10;
                carry = (temp + carry) / 10;
            }
            string ans(m+n, '0');
            for(int i = m+n-1, id = 0; i >= 0; --i)
                ans[id++] = res[i] + '0';
            int start;
            for(int i = 0; i < m+n; ++i)
                if(ans[i] != '0')
                {
                    start = i;
                    break;
                }
            return ans.substr(start);
        }
};

int main()
{
    Solution demo;
    string s1, s2;
    while(cin >> s1 >> s2)
        cout << demo.multiply(s1, s2) << endl;
    return 0;
}
