#include <iostream>
#include <string>
using namespace std;

class Solution 
{
	public:
	    string toHex(int num) 
	    {
	        if(num == 0)
	            return "0";
	        bool flag = false;
	        string res = "";
	        for(int i = 28; i >= 0; i -= 4)
	        {
	            if(((num>>i)&15) || flag)
	            {
	                flag = true;
	                if(((num>>i)&15) < 10)
	                    res += ((num>>i)&15) + '0';
	                else
	                    res += ((num>>i)&15) + 'a' - 10;
	            }
	        }
	        return res;
	    }
};

class Solution {
public:
    string toHex(int num) 
    {
        if(num == 0)
            return "0";
        string res = "";
        vector<char> hex= {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};
        while(num != 0 && res.size() < 8)
        {
            res = hex[num&15] + res;
            num >>= 4;
        }
        return res;
    }
};

int main()
{
    return 0;
}
