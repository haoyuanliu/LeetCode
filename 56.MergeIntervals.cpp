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
        vector<Interval> merge(vector<Interval> &intervals)
        {
            int len = intervals.size();
            vector<Interval> res;
            vector<pair<int, int> > temp;
            for(int i = 0; i < len; ++i)
            {
                temp.push_back(make_pair(intervals[i].start, i+1));
                temp.push_back(make_pair(intervals[i].end, -(i+1)));
            }
            int count = 0;
            int l, r;
            for(int i = 0; i < temp.size(); ++i)
            {
                if(count == 0)
                    l = temp[i].first;
                count += temp[i].second;
                if(count == 0)
                    r = temp[i].first;
                res.push_back(Interval(l, r));
            }
        }
};

int main()
{
    return 0;
}
