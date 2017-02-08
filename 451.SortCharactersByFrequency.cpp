class Solution
{
public:
    string frequencySort(string s)
    {
        string res;
        if(s == "") return res;
        unordered_map<char, int> m;
        priority_queue<pair<int, char>> que;
        for(int i = 0; i < s.size(); ++i)
        {
            m[s[i]]++;
        }
        for(auto it = m.begin(); it != m.end(); ++it)
        {
            que.push(make_pair((*it).second, (*it).first));
        }
        while(!que.empty())
        {
            for(int i = 0; i < que.top().first; ++i)
            {
                res += que.top().second;
            }
            que.pop();
        }
        return res;
    }
};
