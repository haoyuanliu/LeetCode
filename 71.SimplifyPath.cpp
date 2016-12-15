#include <iostream>
#include <string>
#include <stack>
using namespace std;

class Solution
{
    public:
        string simplifyPath(string path)
        {
            string res, temp;
            res = temp = "";
            stack<string> st;
            int len = path.size();
            for(int i = 0; i < len; ++i)
            {
                if(path[i] == '/')
                {
                    if(temp == "" || temp == ".")
                    {
                        temp = "";
                        continue;
                    }
                    else if(temp == "..")
                    {
                        temp = "";
                        if(!st.empty())
                            st.pop();
                    }
                    else
                    {
                        st.push(temp);
                        temp = "";
                    }
                }
                else
                {
                    temp += path[i];
                }
            }
            if(temp != "")
            {
                if(temp == "..")
                {
                    if(!st.empty())
                        st.pop();
                }
                else if(temp != ".")
                    st.push(temp);
            }
            if(st.empty())
                return "/";
            while(!st.empty())
            {
                res = "/" + st.top() + res;
                st.pop();
            }
            return res;
        }
};

int main()
{
    Solution demo;
    string str;
    while(cin >> str)
        cout << demo.simplifyPath(str) << endl;
    return 0;
}
