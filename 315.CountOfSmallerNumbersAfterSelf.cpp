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

bool cmp(const pair<int, int> a, const pair<int, int> b)
{
    return a.first < b.first; 
}

class Solution
{
    public:
        vector<int> countSmaller(vector<int> &nums)
        {
            int len = nums.size();
            vector<int> res(len, 0);
            vector<pair<int, int>> temp;
            for(int i = 0; i < len; ++i)
                temp.push_back(make_pair(nums[i], i));
            solve(res, temp, 0, len);
            return res;
        }
        void solve(vector<int> &res, vector<pair<int, int>> &temp, int start, int end)
        {
            if(end - start <= 1)
                return;
            int mid = (start + end) / 2;
            solve(res, temp, mid, end);
            solve(res, temp, start, mid);
            int r = mid;
            for(int l = start; l < mid; ++l)
            {
                while(temp[l].first > temp[r].first && r < end)
                    r++;
                res[temp[l].second] += r - mid;
            }
            sort(temp.begin() + start, temp.begin() + end, cmp);
        }
};


class Solution
{
    public:
        vector<int> countSmaller(vector<int> &nums)
        {
            int len = nums.size();
            vector<int> res(len, 0);
            vector<int> index;
            for(int i = 0; i < len; ++i)
                index.push_back(i);
            vector<int> numUpdate = nums;
            vector<int> indexUpdate = index;
            solve(res, nums, index, 0, len, numUpdate, indexUpdate);
            return res;
        }
        void solve(vector<int> &res, vector<int> &nums, vector<int> &index, int start, int end, vector<int> &numUpdate, vector<int> &indexUpdate)
        {
            if(end - start <= 1)
                return;
            int mid = (start + end) / 2;
            solve(res, nums, index, mid, end, numUpdate, indexUpdate);
            solve(res, nums, index, start, mid, numUpdate, indexUpdate);
            int r = mid;
            int t = mid;
            int s = start;
            for(int l = start; l < mid; ++l)
            {
                while(nums[l] > nums[r] && r < end)
                    r++;
                while(t < end && nums[t] <= nums[l])
                {
                    numUpdate[s] = nums[t];
                    indexUpdate[s++] = index[t++];
                }
                numUpdate[s] = nums[l];
                indexUpdate[s++] = index[l];
                res[index[l]] += r - mid;
            }
            for(int i = start; i < end; ++i)
            {
                nums[i] = numUpdate[i];
                index[i] = indexUpdate[i];
            }
        }
};



int main()
{
    return 0;
}


class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) 
    {
        int len = nums.size();
        if(len == 0) return vector<int>();
        vector<int> res(len, 0);
        vector<int> index;
        for(int i = 0; i < len; ++i)
            index.push_back(i);
        vector<int> updateNum(nums);
        vector<int> updateIndex(index);
        mergeSort(nums, res, index, updateNum, updateIndex, 0, len);
        return res;
    }
    
    void mergeSort(vector<int> &nums, vector<int> &res, vector<int> &index, vector<int> &updateNum, vector<int> &updateIndex, int left, int right)
    {
        if(right - left < 2) return;
        int mid = (left + right) / 2;
        mergeSort(nums, res, index, updateNum, updateIndex, mid, right);
        mergeSort(nums, res, index, updateNum, updateIndex, left, mid);
        
        int i = mid-1;
        int j = right-1;
        int cur = right-1;
        while(i >= left && j >= mid)
        {
            if(nums[i] > nums[j])
            {
                res[index[i]] += j - mid + 1;
                updateNum[cur] = nums[i];
                updateIndex[cur--] = index[i--];  
            }
            else
            {
                updateNum[cur] = nums[j];
                updateIndex[cur--] = index[j--];
            }
        }
        while(i >= left)
        {
            updateNum[cur] = nums[i];
            updateIndex[cur--] = index[i--];
        }
        while(j >= mid)
        {
            updateNum[cur] = nums[j];
            updateIndex[cur--] = index[j--];
        }
        
        for(i = left; i < right; ++i)
        {
            nums[i] = updateNum[i];
            index[i] = updateIndex[i];
        }
    }
    
};