#include <iostream>
#include <string>
#include <stack>
#include <map>
using namespace std;

class Solution
{
    public:
        bool isValid(string s)
        {
            int len = s.size();
            if(len % 2)
                return false;

            map<char, int> m;
            m.insert(make_pair('{', -1));
            m.insert(make_pair('}', 1));
            m.insert(make_pair('(', -2));
            m.insert(make_pair(')', 2));
            m.insert(make_pair('[', -3));
            m.insert(make_pair(']', 3));

            stack<char> st;
            for(int i = 0; i < len; ++i)
            {
                if(st.empty())
                    st.push(s[i]);
                else
                {
                    if(m[st.top()] + m[s[i]] == 0)
                        st.pop();
                    else
                        st.push(s[i]);
                }
            }
            return st.empty();
        }
};

int main()
{
    Solution res;
    string str;
    while(cin >> str)
    {
        if(res.isValid(str))
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}
