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

bool compare(pair<int, int> a, pair<int, int> b)
{
    if(a.first == b.first)
        return abs(a.second) > abs(b.second);
    else
        return a.first < b.first;
}
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
            sort(temp.begin(), temp.end(), compare);
            for(const auto x : temp)
                cout << x.first << " " << x.second << endl;
            cout << endl;
            int count = 0;
            int l, r;
            for(int i = 0; i < temp.size(); ++i)
            {
                if(count == 0)
                    l = temp[i].first;
                count += temp[i].second;
                if(count == 0)
                {
                    r = temp[i].first;
                    res.push_back(Interval(l, r));
                }
            }
            return res;
        }
};

int main()
{
    Solution demo;
    int a, b;
    vector<Interval> inter;
    while(cin >> a >> b)
    {
        inter.push_back(Interval(a, b));
    }
    vector<Interval> res = demo.merge(inter);
    for(const auto x : res)
        cout << x.start << " " << x.end << endl;
    return 0;
}
