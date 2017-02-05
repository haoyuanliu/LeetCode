class Solution
{
    struct Pairs
    {
        int a, b;
        int sum;
        Pairs(int a_, int b_) : a(a_), b(b_), sum(a + b) {}
        bool operator<(const Pairs ref) { return sum < ref.sum; }
    };
public:
    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k)
    {
        vector<pair<int, int>> res;
        priority_queue<Pairs> que;
        for(int i = 0; i < nums1.size(); ++i)
        {
            que.push(Pairs(nums1[i], nums2[i]));
        }
        for(int i = 0; i < k && !que.empty(); ++i)
        {
            res.push_back(make_pair(que.top().a, que.top().b));
            que.pop();
        }
        return res;
    }
};
