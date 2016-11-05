#include <iostream>
#include <string>
using namespace std;

class Solution
{
    public:
        string conver(string s, int numRows)
        {
            if(numRows == 1)
                return s;
            string res = s;
            int k = 0;
            int len = s.size();
            int interval = (numRows<<1) -2;
            for(int i = 0; i < len; i += interval)
                res[k++] = s[i];
            for(int i = 1; i < numRows-1; ++i)
            {
                int delta = (i<<1);
                for(int j = 1; j < len; j += delta)
                {
                    res[k++] = s[j];
                    delta = interval - delta;
                }
            }
            for(int i = numRows - 1; i < len; i += interval)
                res[k++] = s[i];
            return res;
        }
};

int main()
{
    Solution res;
    string str;
    int n;
    while(cin >> str >> n)
    {
        cout << res.conver(str, n) << endl;
    }
    return 0;
}
