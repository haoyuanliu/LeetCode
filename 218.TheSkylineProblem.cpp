#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <algorithm>
using namespace std;
    
bool cmp(const pair<int, int> a, const pair<int, int> b)
{
    return a.first != b.first ? a.first < b.first : a.second < b.second;
}

class Solution 
{
    public:
        vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) 
        {
            vector<pair<int, int>> res;
            vector<pair<int, int>> heights;
            for(const auto build : buildings)
            {
                heights.push_back(make_pair(build[0], -build[2]));
                heights.push_back(make_pair(build[1], build[2]));
            }
            sort(heights.begin(), heights.end(), cmp);
            unordered_map<int, int> isEnd;
            priority_queue<int> que;
            int pre = 0;
            que.push(0);
            int cur;
            for(const auto height : heights)
            {
                if(height.second < 0)
                {
                    que.push(-height.second);
                }
                else
                {
                    ++isEnd[height.second];
                    while(!que.empty() && isEnd[que.top()] > 0)
                    {
                        --isEnd[que.top()];
                        que.pop();
                    }
                }
                cur = que.top();
                if(cur != pre)
                {
                    pre = cur;
                    res.push_back(make_pair(height.first, cur));
                }
            }
            return res;
        }
};


int main()
{
    vector<vector<int>> buildings;
    vector<int> temp;
    Solution demo;
    int nums;
    for(int i = 0; i < 5; ++i)
    {
        temp.clear();
        for(int j = 0; j < 3; ++j)
        {
            cin >> nums;
            temp.push_back(nums);
        }
        buildings.push_back(temp);
    }
    auto res = demo.getSkyline(buildings);
    for(const auto x : res)
    {
        cout << x.first << " " << x.second << endl;
    }
    return 0;
}
