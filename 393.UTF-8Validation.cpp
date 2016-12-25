#include <iostream>
#include <vector>
using namespace std;

class Solution
{
    public:
        bool validUtf8(vector<int> &data)
        {
            int len = data.size();
            int count = 0;
            for(int i = 0; i < len; ++i)
            {
                if(count == 0)
                {
                    if(data[i]>>5 == 0b110)
                        count = 1;
                    else if(data[i]>>4 == 0b1110)
                        count = 2;
                    else if(data[i]>>3 == 0b11110)
                        count = 3;
                    else if(data[i]>>7)
                        return false;
                }
                else
                {
                    if(data[i]>>6 != 0b10)
                        return false;
                    count--;
                }
            }
            return count == 0;
        }
};

int main()
{
    return 0;
}
