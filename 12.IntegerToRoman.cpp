#include <iostream>
#include <string>
using namespace std;

class Solution
{
    public:
        string intToRoman(int num)
        {
            string res;
            int temp;
            char ch[7] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
            int n[7] = {1, 5, 10, 50, 100, 500, 1000};
            for(int i = 6; i >= 0; i = i-2)
            {
                temp = num / n[i];
                if(temp < 5)
                {
                    if(temp == 4)
                    {
                        res = res + ch[i] + ch[i+1];
                    }
                    else
                    {
                        for(int j = 0; j < temp; ++j)
                            res = res + ch[i];
                    }
                }
                else
                {
                    if(temp == 9)
                    {
                        res = res + ch[i] + ch[i+2];
                    }
                    else
                    {
                        res = res + ch[i+1];
                        for(int j = 5; j < temp; ++j)
                            res = res + ch[i];
                    }
                }
                num = num % n[i];
            }
            return res;
        }
};

int main()
{
    int num;
    Solution res;
    while(cin >> num)
    {
        cout << res.intToRoman(num) << endl;
    }
    return 0;
}
