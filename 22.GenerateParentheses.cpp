#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution
{
    public:
        vector<string> generateParenthesis(int n)
        {
            cout << n << endl;
            vector<string> res;
            string temp = "";
            addStr(n, n, temp, res);
            return res;
        }

        void addStr(int l, int r, string str, vector<string> &ans)
        {
            if(l==0 && r==0)
            {
                ans.push_back(str);
                return;
            }
            if(l)
                addStr(l-1, r, str+"(", ans);
            if(r && l < r)
                addStr(l, r-1, str+")", ans);
        }
};

int main()
{
    Solution res;
    vector<string> ans;
    int num;
    while(cin >> num)
    {
        ans = res.generateParenthesis(num);
        for(const auto x : ans)
            cout << x << endl;
        cout << "######################" << endl;
    }
    return 0;
}
