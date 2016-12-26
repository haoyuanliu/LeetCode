#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution
{
    public:
        vector<int> diffWaysToCompute(string input)
        {
            vector<int> res;
            int len = input.size();
            for(int i = 0; i < len; ++i)
            {
                if(input[i] == '+' || input[i] == '-' || input[i] == '*')
                {
                    vector<int> r1 = diffWaysToCompute(input.substr(0, i));
                    vector<int> r2 = diffWaysToCompute(input.substr(i+1));
                    for(const auto a : r1)
                    {
                        for(const auto b : r2)
                        {
                            if(input[i] == '+')
                                res.push_back(a + b);
                            else if(input[i] == '-')
                                res.push_back(a - b);
                            else if(input[i] == '*')
                                res.push_back(a * b);
                        }
                    }
                }
            }
            if(res.empty())
            {
                int temp = 0;
                for(const auto ch : input)
                {
                    temp = temp * 10 + ch - '0';
                }
                res.push_back(temp);
            }
            return res;
        }
};

int main()
{
    return 0;
}
