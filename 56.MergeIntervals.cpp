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

//Solution I 26ms
bool compare(pair<int, int> a, pair<int, int> b)
{
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
            int count = 0;
            int l, r;
            bool sucess = true;
            for(int i = 0; i < temp.size(); ++i)
            {
                if(count == 0 && sucess)
                {
                    l = temp[i].first;
                    sucess = false;
                }
                count += temp[i].second;
                if(count == 0)
                {
                    if(i < temp.size()-1 && temp[i].first == temp[i+1].first)
                        continue;
                    r = temp[i].first;
                    res.push_back(Interval(l, r));
                    sucess = true;
                }
            }
            return res;
        }
};


//Solution II 16ms
bool comp(Interval a, Interval b)
{
    return a.start < b.start;
}

class Solution
{
    public:
        vector<Interval> merge(vector<Interval> &inter)
        {
            vector<Interval> res;
            int len = inter.size();
            if(len == 0)
                return res;
            sort(inter.begin(), inter.end(), comp);
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
