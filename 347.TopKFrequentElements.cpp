class Solution
{
public:
    vector<int> topKFrequent(vector<int>& nums, int k)
    {
        vector<int> res;
        unordered_map<int, int> m;
        for(int i = 0; i < nums.size(); ++i)
        {
            m[nums[i]]++;
        }
        priority_queue<pair<int, int>> que;
        for(auto it = m.begin(); it != m.end(); ++it)
        {
            que.push(make_pair(it->second, it->first));
        }
        for(int i = 0; i < k; ++i)
        {
            res.push_back(que.top().second);
            que.pop();
        }
        return res;
    }
};
