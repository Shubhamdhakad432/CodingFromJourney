/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void in(TreeNode *s,vector<int>&v)
    {
        if(s==NULL)
        {
            return;
        }
        in(s->left,v);
        v.push_back(s->val);
        in(s->right,v);
    }
    
    vector<int> inorderTraversal(TreeNode* s) {
        vector<int>v;
        in(s,v);
        return v;
    }
};