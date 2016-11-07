#include <iostream>
#include <vector>
#include <string>
using namespace std;
 
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) 
    {
        if(strs.size() == 0)
            return "";
        if(strs.size() == 1)
            return strs[0];
        string res;
        for(int i = 1; i < strs.size(); ++i)
        { 
            int j = 0;
            while(strs[i-1][j] && strs[i][j])
            {
            	cout << j << endl;
                if(strs[i-1][j] == strs[i][j])
                    j++;
                else
                	break;
            }
            strs[i] = strs[i].substr(0, j);
        }
        res = strs[strs.size() - 1];
        return res;
    }
};

int main()
{
	Solution res;
	vector<string> str;
	string s;
	for(int i = 0; i < 2; ++i) 
	{
		cin >> s;
		str.push_back(s);
	}
	cout << res.longestCommonPrefix(str) << endl;
	return 0;
}