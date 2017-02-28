class Solution
{
public:
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people)
    {
        int len = people.size();
        vector<pair<int, int>> res(len, {-1, -1});
        sort(people.begin(), people.end());
        int count, i;
        for(const auto p : people)
        {
            count = 0;
            i = 0;
            for(i = 0; i < len; ++i)
            {
                if(res[i].first == -1 || res[i].first >= p.first)
                    count++;
                if(count > p.second)
                    break;
            }
            res[i].first = p.first;
            res[i].second = p.second;
        }
        return res;
    }
};

class Solution
{
public:
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people)
    {
        auto comp = [](const pair<int, int> &a, const pair<int, int> &b)
        {
            return a.first > b.first || (a.first == b.first && a.second < b.second);
        };

        vector<pair<int, int>> res;
        sort(people.begin(), people.end(), comp);
        for(auto p : people)
            res.insert(res.begin()+p.second, p);
        return res;
    }
};
