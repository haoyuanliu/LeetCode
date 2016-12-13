#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
    public:
        vector<int> plusOne(vector<int> & digits)
        {
            int carry = 1;
            int len = digits.size();
            reverse(digits.begin(), digits.end());

            vector<int> res(len, 0);
            for(int i = 0; i < len; ++i)
            {
                res[i] = (carry + digits[i]) % 10;
                carry = (carry + digits[i]) / 10;
            }
            if(carry)
                res.push_back(1);
            reverse(res.begin(), res.end());
            return res;
        }
};

int main()
{
    return 0;
}
