#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
    public:
        string getPermutation(int n, int k)
        {
            string res = "";
            int nums[n];
            nums[0] = 1;
            for(int i = 1; i < n; ++i)
                nums[i] = i * nums[i-1];
            vector<int> index;
            for(int i = 1; i <= n; ++i)
                index.push_back(i);
            k = k - 1;
            for(int i = n-1; i >= 0; --i)
            {
                int temp = k / nums[i];
                res += *(index.begin() + temp) + '0';
                index.erase(index.begin() + temp);
                k = k % nums[i];
            }
            return res;
        }
};

int main()
{
    Solution demo;
    int n, k;
    while(cin >> n >> k)
        cout << demo.getPermutation(n, k) << endl;
    return 0;
}
