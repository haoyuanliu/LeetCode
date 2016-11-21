#include <iostream>
#include <string.h>
using namespace std;

class Solution
{
    public:
        string countAndSay(int n)
        {
            string res = "";
            string temp = "1";
            if(n == 1)
                return temp;
            n--;
            while(n--)
            {
                res = "";
                int cnt = 1;
                for(int i = 0; i < temp.size(); ++i)
                {
                    while(temp[i] == temp[i+1] && i+1 < temp.size())
                    {
                        cnt++;
                        i++;
                    }
                    res += cnt + '0';
                    res += temp[i];
                    cnt = 1;
                }

                temp = res;
            }
            return res;
        }
};

int main()
{
    Solution demo;
    int num;
    while(cin >> num)
        cout << demo.countAndSay(num) << endl;
    return 0;
}
