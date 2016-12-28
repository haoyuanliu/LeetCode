#include <iostream>
#include <vector>
using namespace std;


class Solution
{
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) 
    {
        int size=nums.size();
        if(size==0)  
        	return 0;
        vector<long> sums(size+1, 0);
        for(int i=0; i<size; i++)  
        	sums[i+1]=sums[i]+nums[i];
        return solve(sums, 0, size+1, lower, upper);
    }
   
    int solve(vector<long>& sums, int start, int end, int lower, int upper)
    {
        if(end-start<=1)  return 0;
        int mid=(start+end)/2;
        int count=solve(sums, start, mid, lower, upper) + solve(sums, mid, end, lower, upper);
        int m=mid, n=mid, t=mid, len=0;
        vector<long> cache(end-start, 0);
        for(int i=start, s=0; i<mid; i++, s++)
        {
            while(m<end && sums[m]-sums[i]<lower) 
            	m++;
            while(n<end && sums[n]-sums[i]<=upper) 
            	n++;
            count+=n-m;
            while(t<end && sums[t]<sums[i]) 
            	cache[s++]=sums[t++];
            cache[s]=sums[i];
            len=s;
        }
        
        for(int i=0; i<=len; i++)  
        	sums[start+i]=cache[i];
        return count;
    }
};

class Solution
{
    public:
        int countRangeSum(vector<int>& nums, int lower, int upper) 
        {
            int len = nums.size();
            if(len == 0)
                return 0;
            vector<long> sums(len+1, 0);
            for(int i = 0; i < len; ++i)
                sums[i+1] = sums[i] + nums[i];
            vector<long> sumUpdate = sums;
            return solve(sums, sumUpdate, 0, len+1, lower, upper);
        }
        int solve(vector<long> &sums, vector<long> &sumUpdate, int start, int end, int lower, int upper)
        {
            if(end - start <= 1)
                return 0;
            int mid = (end + start) / 2;
            int count = solve(sums, sumUpdate, start, mid, lower, upper)
                + solve(sums, sumUpdate, mid, end, lower, upper);
            int l = mid;
            int r = mid;
            int t = mid;
            int s = start;
            for(int i = start; i < mid; ++i)
            {
                while(sums[l] - sums[i] < lower && l < end)
                    l++;
                while(sums[r] - sums[i] <= upper && r < end)
                    r++;
                while(sums[i] > sums[t] && t < end)
                    sumUpdate[s++] = sums[t++];
                sumUpdate[s++] = sums[i];
                count += r - l;
            }
            for(int i = start; i < end; ++i)
                sums[i] = sumUpdate[i];
            return count;
        }
};

int main()
{
    Solution demo;
    int lower = -2;
    int upper = 2;
    vector<int> nums= {-2, 5, -1};
    cout << demo.countRangeSum(nums, lower, upper) << endl;
    return 0;
}
