#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
    	vector<vector<int>> res;
    	if(nums.size() < 3)
    		return res;
    	sort(nums.begin(), nums.end());
		vector<int> temp;
		for(int i = 0; i < nums.size()-2 && nums[i] <= 0; ++i)
		{
			int l = i+1;
			int r = nums.size() - 1;
			while(l < r)
			{
				if(nums[i] + nums[l] + nums[r] < 0)
					l++;
				else if(nums[i] + nums[l] + nums[r] > 0)
					r--;
				else
				{
					temp.push_back(nums[i]);
					temp.push_back(nums[l]);
					temp.push_back(nums[r]);
					res.push_back(temp);
					temp.clear();
					
					while(l < r && nums[l] == nums[l+1])
						l++;
					while(l < r && nums[r] == nums[r-1])
						r--;
					l++;
				}	
			}
			while(i < nums.size()-2 && nums[i] == nums[i+1])
				i++;
		}
		return res;
   }
};

int main()
{
	Solution res;
	vector<int> nums;
	int n;
	int len;
	cin >> len;
	for(int i = 0; i < len; ++i)
	{
		cin >> n;
		nums.push_back(n);
	}
	auto ans = res.threeSum(nums);
	for(auto x : ans)
	{
		for(auto y : x)
		{
			cout << y << " "; 
		}
		cout << endl;
	}
	return 0;
}