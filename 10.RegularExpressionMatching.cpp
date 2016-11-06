#include <iostream>
#include <string>
using namespace std;

class Solution
{
    public:
        bool isMatch(string s, string p)
        {
            if(p.size() == 0)
                return s.size() == 0;
            if(p.size() == 1)
                return (s.size() == 1) && (s[0] == p[0] || p[0] == '.');
            if(p[1] == '*')
            {
                while(s.size() && (s[0]==p[0] || p[0] == '.'))
                {
                    if(isMatch(s, p.substr(2)))
                        return true;
                    s = s.substr(1);
                }
                return isMatch(s, p.substr(2));
            }
            else
            {
                if(s.size() == 0)
                    return false;
                if(s[0]==p[0] || p[0] == '.')
                    return isMatch(s.substr(1), p.substr(1));
                else
                    return false;
            }
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
