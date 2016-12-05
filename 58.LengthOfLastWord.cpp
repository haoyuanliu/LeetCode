#include <iostream>
#include <string>
using namespace std;

class Solution
{
    public:
        int lengthOfLastWord(string s)
        {
            int count = 0;
            int len = s.size();
            for(int i = len-1; i >= 0; --i)
            {
                if(!count && s[i] == ' ')
                    continue;
                if(s[i] == ' ')
                    break;
                count++;
            }
            return count;
        }
};

int main()
{
    Solution demo;
    string str;
    while(getline(cin, str))
        cout << demo.lengthOfLastWord(str) << endl;
    return 0;
}
