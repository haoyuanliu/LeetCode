class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) 
    {
        return solve(nums, 0, nums.size());
    }
    TreeNode* solve(vector<int> &nums, int start, int end)
    {
    	if(start == end || start > end)
    		return NULL;
    	if(end - start == 1)
    		return new TreeNode(nums[start]);
    	int mid = (start + end) / 2;
    	TreeNode* root = new TreeNode(nums[mid]);
    	root->left = solve(nums, start, mid);
    	root->right = solve(nums, mid+1, end);
    	return root;
    }
};