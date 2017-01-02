#include <iostream>
#include <vector>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
public:
    vector<TreeNode*> generateTrees(int n)
    {
        vector<TreeNode *> res;
        vector<int> nums(n, 0);
        for(int i = 0; i < n; ++i)
            nums[i] = i+1;

    }
    void buildTree(vector<TreeNode *> &res, TreeNode *root, vector<int> &nums, int cur)
    {
        if(cur == 0)
        {
            root = new TreeNode(nums[cur]);
            buildTree(res, nums, cur+1);
        }
        else if(cur == nums.size())
        {
            res.push_back(root);
            return;
        }
        else
        {
            TreeNode *p = root;
            while(p)
            {
                if(p == NULL)
                    p = new TreeNode(nums[cur]);
                else
                {
                    if(nums[cur] < p->val)
                    {
                        p = p->left;
                    }
                    else
                    {
                        if(p->left)
                            return;
                        p = p->right;
                    }
                }
            }
        }
    }
    void dfs(vector<TreeNode *> &res, vector<int> &nums,)
};
