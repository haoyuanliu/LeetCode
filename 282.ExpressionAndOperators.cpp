#include <iostream>
#include <vector>
#include <string>
using namespace std;

typedef long long ll;

class Solution
{
    public:
        vector<string> addOperators(string num, int target)
        {
            vector<string> res;
            dfs(res, num.size(), num, target, 0, 0, 0, "");
            return res;
        }
        void dfs(vector<string> &res, int len, string num, ll target, int cur, ll pre, ll val, string path)
        {
            if(cur == len && pre + val == target)
            {
                res.push_back(path);
                return;
            }
            ll temp = 0;
            for(int i = cur; i < len; ++i)
            {
                temp = temp * 10 + num[i] - '0';
                string s = to_string(temp);
                if(cur != 0)
                {
                    dfs(res, len, num, target, i+1, pre+val, temp, path + '+' + s);
                    dfs(res, len, num, target, i+1, pre+val, -temp, path + '-' + s);
                    dfs(res, len, num, target, i+1, pre, temp * val, path + '*' + s);
                }
                else
                    dfs(res, len, num, target, i+1, 0, temp, s);
                if(num[cur] == '0')
                    break;
            }
        }
};

int main()
{
    Solution demo;
    string num;
    int target;
    cin >> target;
    cin >> num;
    auto res = demo.addOperators(num, target);
    for(const auto x : res)
        cout << x << endl;
    return 0;
}
