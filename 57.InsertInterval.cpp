#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Interval
{
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution
{
    public:
        vector<Interval> merge(vector<Interval> &inter)
        {
            vector<Interval> res;
            int len = inter.size();
            if(len == 0)
                return res;
            int lastStart = inter[0].start;
            int lastEnd = inter[0].end;
            for(int i = 0; i < len; ++i)
            {
                if(inter[i].start <= lastEnd)
                {
                    lastEnd = max(lastEnd, inter[i].end);
                }
                else
                {
                    res.push_back(Interval(lastStart, lastEnd));
                    lastStart = inter[i].start;
                    lastEnd = inter[i].end;
                }
            }
            res.push_back(Interval(lastStart, lastEnd));
            return res;
        }

        vector<Interval> insert(vector<Interval> &intervals, Interval newInterval)
        {
            int len = intervals.size();
            if(len == 0)
            {
                intervals.push_back(newInterval);
                return intervals;
            }
            int i = 0;
            while(i < len)
            {
                if(intervals[i].start >= newInterval.start)
                    break;
                i++;
            }
            intervals.insert(intervals.begin()+i, newInterval);
            return merge(intervals);
        }
};

int main()
{
    Solution demo;
    int a, b;
    vector<Interval> inter;
    cin >> a >> b;
    Interval nInter = Interval(a, b);
    while(cin >> a >> b)
    {
        inter.push_back(Interval(a, b));
    }
    vector<Interval> res = demo.insert(inter, nInter);
    for(const auto x : res)
        cout << x.start << " " << x.end << endl;
    return 0;
}
