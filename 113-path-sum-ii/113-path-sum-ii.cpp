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
    void bin(TreeNode *s,vector<vector<int>>&a,vector<int>v,int sum,int k)
    {
        if(s==NULL)
        {
            return;
        }
        sum+=s->val;
        v.push_back(s->val);
        if(s->left==NULL && s->right==NULL && sum==k)
        {
            a.push_back(v);
            return;
        }
        bin(s->left,a,v,sum,k);
        bin(s->right,a,v,sum,k);
    }
    
    vector<vector<int>> pathSum(TreeNode* s, int k) {
        vector<vector<int>>a;
        vector<int>x;
        bin(s,a,x,0,k);
        return a;
    }
};