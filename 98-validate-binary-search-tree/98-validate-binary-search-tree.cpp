class Solution {
public:
    int minv(TreeNode *s)
    {
        if(s==NULL) return INT_MAX;
        if(s->left==NULL && s->right==NULL) return s->val;
        return min(s->val,min(minv(s->left),minv(s->right)));
    }
    
    int maxv(TreeNode *s)
    {
        if(s==NULL) return INT_MIN;
        if(s->left==NULL && s->right==NULL) return s->val;
        return max(s->val,max(maxv(s->left),maxv(s->right)));
    }
    
    bool isValidBST(TreeNode* s) {
        if(s==NULL) return true;
        if(s->left==NULL && s->right==NULL) return true;
        int x=INT_MAX,y=INT_MIN;
        if(s->right==NULL)
        {
            y=maxv(s->left);
            if(s->val>y)
            {
                return isValidBST(s->left);
            }
            else
            {
                return false;
            }
        }
        else if(s->left==NULL)
        {
            x=minv(s->right);
            if(s->val<x)
            {
                return isValidBST(s->right);
            }
            else
            {
                return false;
            }
        }
        else
        {
            x=minv(s->right);
            y=maxv(s->left);
            if(s->val>y && s->val<x)
            {
                return isValidBST(s->left)&&isValidBST(s->right);
            }
            else
            {
                return false;
            }
        }
    }
    
    
    
};