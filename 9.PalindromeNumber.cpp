#include <iostream>
using namespace std;

class Solution
{
    public:
        bool isPalindrome(int x)
        {
            if(x < 0)
                return false;
            int num, res;
            res = 0;
            num = x;
            while(num)
            {
                res =  res * 10 + num%10;
                num /= 10;
            }
            if(x == res)
                return true;
            else
                return false;
        }
};

int main()
{
    Solution res;
    int num;
    while(cin >> num)
    {
        if(res.isPalindrome(num))
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}
