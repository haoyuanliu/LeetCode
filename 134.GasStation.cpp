//Solution I TLE
class Solution
{
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost)
    {
        int len = gas.size();
        int amount;
        for(int i = 0; i < len; ++i)
        {
            amount = 0;
            if(gas[i] < cost[i])
                continue;
            for(int j = i; j < i+len; ++j)
            {
                int cur = j % len;
                amount += gas[cur];
                if(amount < cost[cur])
                    j = len+len;
                amount -= cost[cur];
                if(j == i + len - 1)
                    return i;
            }
        }
        return -1;
    }
};

//Solution II
class Solution
{
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost)
    {
        int total = 0;
        int tank = 0;
        int start = 0;
        for(int i = 0; i < gas.size(); ++i)
        {
            if((tank = tank + gas[i] - cost[i]) < 0)
            {
                start = i+1;
                total += tank;
                tank = 0;
            }
        }
        return (total + tank >= 0) ? start : -1;
    }
};
