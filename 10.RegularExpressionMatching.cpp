#include <iostream>
#include <string>
using namespace std;

class Solution
{
    public:
        bool isMatch(string s, string p)
        {
            int la = s.size();
            int lb = p.size();
            int i, j;
            i = j  = 0;
            while(i < la && j <lb)
            {
                if(s[i] == p[j])
                {
                    if(p[i+1] == '*')
                    {
                        if(s[j+1] == s[j])
                            i++;
                        else
                        {
                            i++;
                            j++;
                        }
                    }
                    else
                    {
                        i++;
                        j++;
                    }
                }
                else
                {
                    if(p[i+1] == '*')
                    {
                        i++;
                        j++;
                        j++;
                    }
                    else
                    {
                        return false;
                    }
                }
            }
            return true;
        }
};

int main()
{
    string s1, s2;
    Solution res;
    while(cin >> s1 >> s2)
    {
        if(res.isMatch(s1, s2))
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}
