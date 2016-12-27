#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class FenwickTree
{
    vector<int> sumArray;
    int n;
    inline int lowBit(int x)
    {
        return x & -x;
    }

public:
    FenwickTree(int n) : n(n), sumArray(n+1, 0) {}

    void add(int x, int d)
    {
        while(x <= n)
        {
            sumArray[x] += d;
            x += lowBit(x);
        }
    }

    int sum(int x)
    {
        int res = 0;
        while(x > 0)
        {
            res += sumArray[x];
            x -= lowBit(x);
        }
        return res;
    }
};

class Solution
{
    public:
        vector<int> countSmaller(vector<int> &nums)
        {
            vector<int> temp = nums;
            sort(temp.begin(), temp.end());
            unordered_map<int, int> dic;
            for(int i = 0; i < temp.size(); ++i)
                dic[temp[i]] = i+1;
            FenwickTree tree(nums.size());
            vector<int> res(nums.size(), 0);
            for(int i = nums.size()-1; i >= 0; --i)
            {
                res[i] = tree.sum(dic[nums[i]] - 1);
                tree.add(dic[nums[i]], 1);
            }
            return res;
        }
};

int main()
{
    return 0;
}
