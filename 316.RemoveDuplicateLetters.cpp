class Solution
{
public:
    string removeDuplicateLetters(string s)
    {
        string res = "0";
        int len = s.size();
        int m[256] = {0};
        int visited[256] = {0};
        for(int i = 0; i < len; ++i)
            m[s[i]]++;

        for(const auto c : s)
        {
            m[c]--;
            if(visited[c]) continue;
            while(c < res.back() && m[res.back()])
            {
                visited[res.back()] = 0;
                res.pop_back();
            }
            res += c;
            visited[c] = 1;
        }
        return res.substr(1);
    }
};
