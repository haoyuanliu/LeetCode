class Solution
{
public:
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people)
    {
        int len = people.size();
        vector<pair<int, int>> res(len, {0, 0});
        vector<int> visited(len, 0);

        sort(people.begin(), people.end());

        for(const auto p : people)
        {
            int count = 0;
            int i = 0;
            for(int i = 0; i < len; ++i)
            {
                if(visited[i] == 0)
                    count++;
                if(count > p.second)
                    break;
            }
            res[i].first = p.first;
            res[i].second = p.second;
            visited[i] = 1;
        }
        return res;
    }
};
