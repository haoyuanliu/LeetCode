class Solution
{
public:
    int findMaximizedCapital(int k, int W, vector<int>& Profits, vector<int>& Capital)
    {
        int res = W;
        priority_queue<int> doable;
        vector<pair<int, int>> notdoable;

        for(int i = 0; i < Profits.size(); ++i)
        {
            if(Profits[i])
            {
                if(Capital[i] <= W)
                    doable.push(Profits[i]);
                else
                    notdoable.push_back(make_pair(Profits[i], Capital[i]));
            }
        }
        while(k-- && doable.size())
        {
            res += doable.top();
            doable.pop();
            for(auto it = notdoable.begin(); it != notdoable.end(); )
            {
                if(it->second <= res)
                {
                    doable.push(it->first);
                    it = notdoable.erase(it);
                }
                else
                    it++;
            }
        }
        return res;
    }
};
