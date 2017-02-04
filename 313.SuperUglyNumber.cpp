class Solution
{
public:
    int nthSuperUglyNumber(int n, vector<int>& primes)
    {
        int res = 1;
        if(n == 1)
            return res;
        priority_queue<int> heap;
        for(int i = 0; i < primes.size(); ++i)
            heap.push(-1 * primes[i]);
        int t = n - 1;
        while(t--)
        {
            int temp = heap.top();
            heap.pop();
            res = -1 * temp;
            for(int i = 0; i < primes.size(); ++i)
                heap.push(temp - primes[i]);

        }
        return res;
    }
};
