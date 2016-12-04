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
        vector<Interval> insert(vector<Interval> &intervals, Interval newInterval)
        {
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
