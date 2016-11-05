#include <iostream>
#include <string>
using namespace std;

class Solution
{
    public:
        string convert(string s, int numRows)
        {
            if(numRows == 1)
                return s;
            string res = s;
            int len = s.size();
            int k = 0;
            int interval = (numRows << 1) - 2;
            for(int i = 0; i < len; i += interval)
                 res[k++] = s[i];
            for(int i = 1; i < numRows - 1; ++i)
            {
                int delta = (i<<1);
                for(int j = i; j < len; j += delta)
                {
                    res[k++] = s[j];
                    delta = interval - delta;
                }
            }
            for(int i = numRows-1; i < len; i += interval)
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
        cout << res.convert(str, n) << endl;
    }
    return 0;
}
