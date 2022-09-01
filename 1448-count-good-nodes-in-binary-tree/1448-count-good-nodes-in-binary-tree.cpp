class Solution {
public:
    int check(TreeNode* root,int maxi,int &ans)
    {
        if(!root) return ans;
		if(root->val>=maxi)
        {
            maxi=max(maxi,root->val);
            ans++;
        }
        
        check(root->left,maxi,ans);
        check(root->right,maxi,ans);
        return ans;
    }
    int goodNodes(TreeNode* root) 
    {
		int ans=0;
		return check(root,INT_MIN,ans);
    }
};