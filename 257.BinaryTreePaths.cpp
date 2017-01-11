//Solution I
class Solution 
{
public:
    vector<string> binaryTreePaths(TreeNode* root) 
    {
        vector<string> res;
        if(root == NULL) return res;
        dfs(res, root, "");
        return res;
    }
    string numToChar(int num)
    {
    	if(num < 0)
    		return '-' + numToChar(abs(num));
    	string res = "";
    	while(num)
    	{
    		res = char(num%10 + '0') + res;
    		num = num / 10;
    	}
    	return res;
    }
    void dfs(vector<string> &res, TreeNode* root, string str)
    {
    	if(!root->left && !root->right)
    	{
    		res.push_back(str+numToChar(root->val));
    		return;
    	}
    	if(root->left) dfs(res, root->left, str+numToChar(root->val)+"->");
    	if(root->right) dfs(res, root->right, str+numToChar(root->val)+"->");
    }
};

class Solution 
{
public:
    vector<string> binaryTreePaths(TreeNode* root) 
    {
        vector<string> res;
        if(root == NULL) return res;
        dfs(res, root, "");
        return res;
    }
    void dfs(vector<string> &res, TreeNode* root, string str)
    {
    	if(!root->left && !root->right)
    	{
    		res.push_back(str+to_string(root->val));
    		return;
    	}
    	if(root->left) dfs(res, root->left, str+to_string(root->val)+"->");
    	if(root->right) dfs(res, root->right, str+to_string(root->val)+"->");
    }
};