class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
    {
        double res = 0;
        int len1 = nums1.size();
        int len2 = nums2.size();
        int mid = (len1 + len2 + 1) / 2;
        int count, i, j;
        double pre, cur;
        count = i = j = 0;
        while(i < nums1.size() && j < nums2.size())
        {
            count++;
            if(count == mid)
                pre = min(nums1[i], nums2[j]);
            else if(count == mid+1)
                cur = min(nums1[i], nums2[j]);
            else if(count > mid+1) break;
            if(nums1[i] < nums2[j])
                i++;
            else
                j++;
        }
        while(i < nums1.size())
        {
            count++;
            if(count == mid)
                pre = nums1[i];
            else if(count == mid+1)
                cur = nums1[i];
            else if(count > mid+1) break;
            i++;
        }
        while(j < nums2.size())
        {
            count++;
            if(count == mid)
                pre = nums2[j];
            else if(count == mid+1)
                cur = nums2[j];
            else if(count > mid+1) break;
            j++;
        }
        if((len1 + len2) % 2)
            return pre;
        else
            return (pre + cur) / 2;
    }
};
