class Solution {
public:
    bool dfs(TreeNode* root)
    {
        if(root == NULL)
            return true;
        
        bool left = dfs(root -> left);
        bool right = dfs(root -> right);
        
        if(left)
            root -> left = NULL;
        if(right)
            root -> right = NULL;
        
        return root -> val == 0 && left && right;
    }
    
    TreeNode* pruneTree(TreeNode* root) {
        
        if(root == NULL)
            return NULL;
        
        bool ans = dfs(root);
        if(ans == true)
            return NULL;
        return root;
    }
};