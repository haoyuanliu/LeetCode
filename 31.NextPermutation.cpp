#include <iostream>
#include <vector>
using namespace std;

class Solution
{
    public:
        void nextPermutation(vector<int> &nums)
        {
            int start = -1;
            for(int i = nums.size() - 2; i >= 0; --i)
            {
                if(nums[i] < nums[i+1])
                {
                    start = i;
                    break;
                }
            }
            if(start == -1)
            {
                int i = 0;
                int j = nums.size() - 1;
                while(i < j)
                {
                    int temp = nums[i];
                    nums[i] = nums[j];
                    nums[j] = temp;
                    i++;
                    j--;
                }
                return;
            }
            for(int i = nums.size() -1; i > start; --i)
                if(nums[i] > nums[start])
                {
                    int temp = nums[start];
                    nums[start] = nums[i];
                    nums[i] = temp;
                    break;
                }
            int i = start+1;
            int j = nums.size()-1;
            while(i < j)
            {
                int temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
                i++;
                j--;
            }
        }
};

int main()
{
    Solution test;
    vector<int> vec;
    int temp;
    while(cin >> temp)
        vec.push_back(temp);
    test.nextPermutation(vec);
    return 0;
}
