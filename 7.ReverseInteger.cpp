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
                temp = p % 10;
                p = p / 10;
                res = res * 10 + temp;
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
