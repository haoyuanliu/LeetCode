//Solution I TLE
class Solution
{
public:
    int nthSuperUglyNumber(int n, vector<int>& primes)
    {
        int res = 1;
        if(n == 1) return res;
        priority_queue<int> heap;
        for(int i = 0; i < primes.size(); ++i)
            heap.push(-1 * primes[i]);
        int t = n - 1;
        while(t--)
        {
            if(heap.empty()) return res;
            while(heap.top() == res)
                heap.pop();
            res = heap.top();
            heap.pop();
            for(int i = 0; i < primes.size(); ++i)
                heap.push(res * primes[i]);
        }
        return -1 * res;
    }
};


//Solution II
class Solution
{
public:
    int nthSuperUglyNumber(int n, vector<int>& primes)
    {
        vector<int> res(n, 1);
        vector<int> idx(primes.size(), 0);
        if(n == 1) return res[0];
        for(int i = 1; i < n; ++i)
        {
            res[i] = 0x7fffffff;
            for(int j = 0; j < primes.size(); ++j)
            {
                res[i] = min(res[i], primes[j] * res[idx[j]]);
            }
            for(int j = 0; j < primes.size(); ++j)
            {
                while(res[idx[j]] * primes[j] <= res[i])
                    idx[j]++;
            }
        }
        return res[n-1];
    }
};
