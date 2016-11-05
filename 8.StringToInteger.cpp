#include <iostream>
#include <string>
using namespace std;

class Solution
{
    public:
        int myAtoi(string str)
        {
            int len = str.length();
            int res = 0;
            int temp = 0;
            bool neg = false;
            int count = 0;
            for(int i = 0; i < len; ++i)
            {
                if(res > (0x7fffffff)/10)
                {
                    temp = str[i] -  '0';
                    if(temp >= 10 || temp < 0)
                        if(neg)
                            return (-1)*res;
                        else
                            return res;
                    else
                        if(neg)
                            return (1<<31);
                        else
                            return (0x7fffffff);   
                }
                else if(res == (0x7fffffff)/10)
                {
                    if(i != len -1)
                        return 0;
                    if(neg)
                    {
                        if(str[i] - '0' == 8)
                            return (1<<31);
                        else if(str[i] - '0' > 8)
                            return (1<<31);
                        else
                            return (-1)*((0x7fffffff)/10*10 + str[i] - '0');
                    }
                    else
                    {
                        if(str[i] - '0' > 8)
                            return (1<<31);
                        else if(str[i] - '0' == 8)
                            return (0x7fffffff);
                        else
                            return ((0x7fffffff)/10*10 + str[i] - '0');
                    }
                }
                if(str[i] == ' ' && !res && !count)
                    continue;
                else if(str[i] == '+')
                {
                    if(count == 0)
                    {
                        neg == false;
                        count++;
                    }
                    else
                        return 0;   
                }
                else if(str[i] == '-')
                {  
                    if(count == 0)
                    {
                        neg = true;
                        count++;
                    }
                    else
                        return 0;
                }
                else
                {
                    temp = str[i] - '0';
                    if(temp < 0 || temp >= 10)
                    {
                        break;
                    }
                    res =  res*10 + temp;
                }
            }
            if(neg)
                return (-1)*res;
            else
                return res;
        }
};

int main()
{
    Solution res;
    string str;
    while(cin >> str)
    {
        cout << res.myAtoi(str) << endl;
    }
    return 0;
}
