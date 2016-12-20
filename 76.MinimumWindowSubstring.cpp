#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;

class Solution
{
    public:
        string minWindow(string s, string t)
        {
            vector<int> ch(128, 0);
            for(int i = 0; i < t.size(); ++i)
                ch[t[i]]++;
            int count = t.size();
            int begin, end, head, resLen;
            begin = end = head = 0;
            resLen = s.size() + 1;
            while(end < s.size())
            {
                if(ch[s[end++]]-- > 0)
                    count--;
                while(count == 0)
                {
                    if(end - begin < resLen)
                    {
                        resLen = end - begin;
                        head = begin;
                    }
                    if(ch[s[begin++]]++ == 0)
                        count++;
                }
            }
            return resLen==s.size()+1 ? "" : s.substr(head, resLen);
        }
};

int main()
{
    return 0;
}
