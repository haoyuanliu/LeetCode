#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	bool isNumber(string s) {
		int i = 0, n = s.length();
		while (n > 0 && s[n - 1] == ' ') n--;
		if (!n) return false;
		while (i <n &&s[i] == ' ') i++;
 
		if (s[i] == '-' || s[i] == '+') i++;
		bool e = false, point = false;
		bool  numBeforeE = false, numAfterE = false;
		bool  numBeforeP = false, numAfterP = false;
		for (; i < n; i++){
			if (s[i] > '9' || s[i] < '0'){
				if (s[i] == 'e' && !e && numBeforeE){
					e = true;
					if (i + 1 < n && (s[i + 1] == '-' || s[i + 1] == '+')) i++;
					continue;
				}
				if (s[i] == '.' && !point  &&!e){
					point = true;
					continue;
				}
				return false;
			}
			numBeforeP = numBeforeE = true;
			if (e)		numAfterE = true;
			if (point)  numAfterP = true;
		}
		if (e && !numAfterE) return false;
		if (point && !numAfterP && !numBeforeP) return false;
		return true;
	}
};

int main()
{
    return 0;
}
