#include <iostream>
#include <vector>
using namespace std;

class Solution
{
    private:
        int mode = 1337;
    public:
        int superPow(int a, vector<int> &b)
        {
            int res = 1;
            if(a == 0)
                return 0;
            for(int i = b.size()-1; i >= 0; --i)
            {
                res = res * quickPow(a, b[i]) % mode;
                a = quickPow(a, 10);
            }
            return res;
        }
        inline int quickPow(int a, int n)
        {
            int res = 1;
            a %= mode;
            while(n)
            {
                if(n & 1)
                    res = res * a % mode;
                a = a * a % mode;
                n >>= 1;
            }
            return res;
        }
};

int main()
{
    return 0;
}
