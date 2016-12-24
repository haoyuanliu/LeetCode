#include <iostream>
using namespace std;

class Solution
{
    public:
        bool isPowerOfTwo(int n)
        {
            if(n == 0 || n&(1<<31))
                return false;
            for(int i = 0; i < 32; ++i)
                if((n & (1<<i)) == n)
                    return true;
            return false;
        }
};
int main()
{
	Solution demo;
    int temp;
	while(cin >> temp)
	{
		if(demo.isPowerOfTwo(temp))
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
    return 0;
}
