#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution
{
    public:
        vector<string> letterCombinations(string digits)
        {
            string str[10] = {" ", " ", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
            int len[10] = {1, 1, 3, 3, 3, 3, 3, 4, 3, 4};
            vector<string> res;
            if(digits == "")
                return res;
            res.push_back("");
            for(int i = 0; i < digits.size(); ++i)
            {
                int sz = res.size();
                for(int j = 0; j < sz; ++j)
                {
                    string cur = res[0];
                    res.erase(res.begin());
                    for(int k = 0; k < len[digits[i]-'0']; ++k)
                    {
                        res.push_back(cur + str[digits[i] - '0'][k]);
                    }
                }
            }
            return res;
        }
};


int main()
{
    Solution res;
    string str;
    vector<string> ans;
    while(cin >> str)
        ans = res.letterCombinations(str);
    return 0;
}
