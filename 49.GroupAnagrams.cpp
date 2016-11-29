#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
using namespace std;

//Solution I 78ms
class Solution
{
    public:
        vector<vector<string> > groupAnagrams(vector<string> &strs)
        {
            vector<vector<string> > res;
            vector<string> s;
            map<string, int> m;
            map<string, int>::iterator it;
            string temp;
            int id = 0;
            for(int i = 0; i < strs.size(); ++i)
            {
                temp = strs[i];
                sort(temp.begin(), temp.end());
                it = m.find(temp);
                if(it == m.end())
                {
                    m[temp] = id++;
                    s.clear();
                    s.push_back(strs[i]);
                    res.push_back(s);
                }
                else
                {
                    res[it->second].push_back(strs[i]);
                }
            }
            return res;
        }
};

int main()
{
    return 0;
}
