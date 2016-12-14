#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution
{
    public:
        vector<string> fullJustify(vector<string> &words, int maxWidth)
        {
            int len = words.size();
            vector<string> res;
            vector<string> temp;
            string str;
            int count = 0;
            int totalLen = 0;
            for(int i = 0; i < len; ++i)
            {
                if(count + totalLen + words[i].size() > maxWidth)
                {
                    str = "";
                    str += temp[0];
                    if(count == 1)
                    {
                        str += string(maxWidth - totalLen, ' ');
                    }
                    else if(count == 2)
                    {
                        str += string(maxWidth - totalLen, ' ');
                        str += temp[1];
                    }
                    else
                    {
                        int block = (maxWidth - totalLen) / (count - 1);
                        int last = maxWidth - totalLen - block * (count - 1);
                        for(int j = 1; j < count; ++j)
                        {
                            str += string(block, ' ');
                            if(last-- > 0)
                                str += ' ';
                            str += temp[j];
                        }
                    }
                    res.push_back(str);
                    temp.clear();
                    temp.push_back(words[i]);
                    count = 1;
                    totalLen = words[i].size();
                }
                else
                {
                    temp.push_back(words[i]);
                    count++;
                    totalLen += words[i].size();
                }
            }
            if(count)
            {
                str = "";
                str += temp[0];
                for(int j = 1; j < temp.size(); ++j)
                {
                    str += ' ';
                    str += temp[j];
                }
                str += string(maxWidth - totalLen - count + 1, ' ');
                res.push_back(str);
            }
            return res;
        }
};

int main()
{
    Solution demo;
    vector<string> strs;
    string s;
    int maxLen;
    cin >> maxLen;
    while(cin >> s)
        strs.push_back(s);
    auto res = demo.fullJustify(strs, maxLen);
    for(const auto x : res)
        cout << x << endl;
    return 0;
}
