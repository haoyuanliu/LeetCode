#include <iostream>
#include <vector>
using namespace std;
class Solution
  {
    public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
    {
          vector<double> res;
          int la = nums1.size();
          int lb = nums2.size();
          int mid = (la + lb) / 2;
          int i = 0;
          int j = 0;
          double ans;
          while(i < la && j < lb)
          {
              if(nums1[i] > nums2[j])
              {
                  res.push_back(nums2[j]);
                  j++;
              }
              else
              {
                  res.push_back(nums1[i]);
                  i++;
              }
          }
          while(i < la)
          {
              res.push_back(nums1[i]);
              i++;
          }
          while(j < lb)
          {
              res.push_back(nums2[j]);
              j++;
          }
          if((la+lb) % 2)
              ans = res[mid];
          else
            ans = (res[mid]+res[mid-1])/2;
          return ans;
    }
};
int main()
{
  vector<int> a = {1, 3};
  vector<int> b = {2};
  Solution res;
  cout << res.findMedianSortedArrays(a, b) << endl;
  return 0;
}
