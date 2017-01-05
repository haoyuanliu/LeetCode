class Solution 
{
public:
    unordered_map<int, int> m;
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) 
    {
        for(int i = 0; i < inorder.size(); ++i)
        	m[inorder[i]] = i;
        return solve(inorder, postorder, 0, inorder.size(), 0, inorder.size());
    }
    TreeNode *solve(vector<int> &inorder, vector<int>& postorder, int s1, int e1, int s2, int e2)
    {
    	if(e1 == s1 || e1 < s1)
    		return NULL;
    	if(e1 - s1 == 1)
    		return new TreeNode(inorder[s1]);
    	int mid = m[postorder[e2-1]];
    	TreeNode* root = new TreeNode(postorder[e2-1]);
    	root->left = solve(inorder, postorder, s1, mid, s2, s2+mid-s1);
    	root->right = solve(inorder, postorder, mid+1, e1, s2+mid-s1, e2-1);
    	return root;
    }
};