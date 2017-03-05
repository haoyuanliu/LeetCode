class Solution
{
public:
    int findMinArrowShots(vector<pair<int, int>>& points)
    {
        if(points.size() == 0)
            return 0;
        auto cmp = [](const pair<int, int> &a, const pair<int, int> &b)
        {
            return a.first < b.first;
        };
        sort(points.begin(), points.end(), cmp);

        int res = 1;
        int left = points[0].first;
        int right = points[0].second;
        for(int i = 1; i < points.size(); ++i)
        {
            if(points[i].first > right)
            {
                res++;
                left = points[i].first;
                right = points[i].second;
            }
            else
            {
                left = max(left, points[i].first);
                right = min(right, points[i].second);
            }
        }
        return res;
    }
};
