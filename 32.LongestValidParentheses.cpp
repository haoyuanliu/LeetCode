#include <iostream>
#include <string>
#include <stack>
using namespace std;

class Solution
{
    public:
        int longestValidParentheses(string s)
        {
            int len = s.size();
            stack<int> stack;
            int match[len];
            for(int i = 0; i < len; ++i)
            {
                match[i] = 0;
                if(s[i] == ')' && !stack.empty())
                {
                    match[stack.top()] = match[i] = 1;
                    stack.pop();
                }
                else if(s[i] == '(')
                    stack.push(i);
            }
            int temp = 0;
            int res = 0;
            for(int i = 0; i < len; ++i)
            {
                if(match[i] == 0)
                {
                    res = res > temp ? res : temp;
                    temp = 0;
                    continue;
                }
                temp++;
            }
            res = res > temp ? res : temp;
            return res;
        }
};

int main()
{
    Solution demo;
    string str;
    while(cin >> str)
        cout << demo.longestValidParentheses(str) << endl;
    return 0;
}
