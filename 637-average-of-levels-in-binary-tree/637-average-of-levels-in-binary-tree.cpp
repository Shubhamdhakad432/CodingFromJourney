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
    vector<double> averageOfLevels(TreeNode* s) {
        vector<double>v;
        queue<TreeNode*>q;
        
        if(s)
            q.push(s);
        else
            return {};
        
        while(!q.empty())
        {
            int n=q.size();
            long sum=0;
            
            for(int i=0;i<n;i++)
            {
                auto x=q.front();
                q.pop();
                
                sum+=x->val;
                
                if(x->left)
                    q.push(x->left);
                if(x->right)
                    q.push(x->right);
            }
            
            if(n==0)
            {
                continue;
            }
            
            double p = 1.0;
            p = p*sum;
            p = p/n;
            v.push_back(p);
        }
        return v;
    }
};