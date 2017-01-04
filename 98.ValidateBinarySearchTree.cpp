class Solution 
{
public:
    bool isValidBST(TreeNode* root) 
    {
        TreeNode* pre = NULL;
        return midOrder(root, pre);
    }
    bool midOrder(TreeNode* root, TreeNode* &pre)
    {
        if(root)
        {
            if(!midOrder(root->left, pre))
                return false;
            if(pre && root->val <= pre->val) 
                return false; 
            pre = root;
            if(!midOrder(root->right, pre))
                return false;
        }
        return true;
    }
};