#include <iostream>
#include <vector>
using namespace std;

class Solution
{
    public:
        vector<string> readBinaryWatch(int num)
        {
            vector<string> res;
            int hours = 0;
            int minutes = 0;
            solve(res, num, hours, minutes, 0);
            return res;
        }
        void solve(vector<string> &res, int count, int &hours, int &minutes, int cur)
        {
            if(hours > 11 || minutes > 59)
                return;
            if(count == 0)
            {
                string temp = "";
                if(hours < 10)
                {
                    temp += hours - 0 + '0';
                }
                else
                {
                    temp += hours / 10 + '0';
                    temp += hours % 10 + '0';
                }
                temp += ":";
                temp += minutes / 10 + '0';
                temp += minutes % 10 + '0';
                res.push_back(temp);
            }
            else
            {
                for(int i = cur; i < 10; ++i)
                {

                    if(i < 6 && (minutes&(1<<i)) == 0)
                    {
                        minutes += (1<<i);
                        solve(res, count-1, hours, minutes, i+1);
                        minutes -= (1<<i);
                    }
                    if(i >= 6 && (hours&(1<<(i-6))) == 0)
                    {
                        hours += (1<<(i-6));
                        solve(res, count-1, hours, minutes, i+1);
                        hours -= (1<<(i-6));
                    }
                }
            }
        }
};

int main()
{
    return 0;
}
