class Solution
{
public:
    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k)
    {
        vector<pair<int, int>> res;
        priority_queue<pair<int, pair<int, int>>> que;
        for(int i = 0; i < nums1.size(); ++i)
        {
            for(int j = 0; j < nums2.size(); ++j)
            {
                que.push(make_pair(-nums1[i]-nums2[j], make_pair(nums1[i], nums2[j])));
            }
        }
        for(int i = 0; i < k && !que.empty(); ++i)
        {
            res.push_back(make_pair(que.top().second.first, que.top().second.second));
            que.pop();
        }
        return res;
    }
};
