#include <iostream>
using namespace std;

class Solution
{
    public:
        int reverse(int x)
        {
            int p = x;
            int res = 0;
            int temp;
            while(p)
            {
                if(res > (0x7FFFFFFF)/10 || res < (1<<31)/10)
                    return 0;
                temp = p % 10;
                p = p / 10;
                res = res * 10 + temp;
                cout << res << endl;
            }
            return res;
        }
};

int main()
{
    Solution res;
    int num;
    while(cin >> num)
        cout << res.reverse(num) << endl;
    return 0;
}
