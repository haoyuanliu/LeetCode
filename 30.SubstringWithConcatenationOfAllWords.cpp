#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

class Solution
{
    public:
        vector<int> findSubstring(string s, vector<string> &words)
        {
            int i, j;
            int wordNum = words.size();
            int wordLen = words[0].size();
            int startLen = s.size() - wordLen * wordNum;
            map<string, int> word;
            for(int i = 0; i < wordNum; ++i)
                ++word[words[i]];
            map<string, int> count;
            vector<int> res;
            string temp;
            for(i = 0; i <= startLen; ++i)
            {
                count.clear();
                for(j = 0; j < wordNum; ++j)
                {
                    temp = s.substr(i + wordLen * j, wordLen);
                    if(word.find(temp) == word.end() || ++count[temp] > word[temp])
                        break;
                }
                if(j == wordNum)
                    res.push_back(i);
            }
            return res;
        }
};

int main()
{
    Solution res;
    vector<int> ans;
    string str, temp;
    vector<string> words;
    cin >> str;
    while(cin >> temp)
    {
        words.push_back(temp);
    }
    ans = res.findSubstring(str, words);
    for(const auto x : ans)
        cout << x << " ";
    cout << endl;
    return 0;
}
