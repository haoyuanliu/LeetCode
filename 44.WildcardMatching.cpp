#include <iostream>
#include <string>
using namespace std;

class Solution
{
    public:
        bool isMatch(string s, string p)
        {

        }
};

int main()
{
    Solution demo;
    string s1, s2;
    while(cin >> s1 >> s2)
    {
        if(demo.isMatch(s1, s2))
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}
