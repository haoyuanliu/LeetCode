/**
 * Definition for an interval.
 * struct Interval
 * {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution
{
public:
    int eraseOverlapIntervals(vector<Interval>& intervals)
    {
        int res = 0;
        int len = intervals.size();
        if(len < 2) return res;
        auto cmp = [](const Interval &a, const Interval &b)
        {
            return a.start < b.start || (a.start == b.start && a.end - a.start < b.end - b.start);
        };

        sort(intervals.begin(), intervals.end(), cmp);
        int pre = 0;
        for(int i = 1; i < len; ++i)
        {
            if(intervals[i].start < intervals[pre].end)
            {
                res++;
                if(intervals[i].end < intervals[pre].end)
                    pre = i;
            }
            else
                pre = i;
        }
        return res;
    }
};
