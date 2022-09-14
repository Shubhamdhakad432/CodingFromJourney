class Solution {
public:
     bool isLeaf(TreeNode* root){
        return !root->left && !root->right;
    }
    
    void preOrderTraversal(TreeNode* root,vector<int> m,int &ans){
        if(root == NULL) return;
          m[root->val]++;
        
        if(isLeaf(root)){
            int oddcount = 0;
            
            for(auto x:m){
                if(x % 2){
                    oddcount++;
                }
            }
            
            if(oddcount<=1){
                ans++;
            }
            
            return;
        }else{
            preOrderTraversal(root->left, m,ans);
            preOrderTraversal(root->right, m,ans);
        }
        
        
    }
    int pseudoPalindromicPaths (TreeNode* root){
        if(root == NULL){
            return 1;
        }
        int ans = 0;
        vector<int> m(10);
        preOrderTraversal(root,m,ans);
        return ans;
    }
};