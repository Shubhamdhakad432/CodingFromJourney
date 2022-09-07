class Solution {
public:
    void chk(TreeNode* s,string &t)
    {
        if(s==NULL) return;
        t+=(string)to_string(s->val);
        
        if(s->left==NULL && s->right==NULL)
        {
            return;
        }
        
        t.push_back('(');
        chk(s->left,t);
        t.push_back(')');
        
        if(!s->right) return;
        
        t.push_back('(');
        chk(s->right,t);
        t.push_back(')');
    }
    
    
    string tree2str(TreeNode* s) {
        if(!s) return "";
        
        string ans="";
        chk(s,ans);
        return ans;
    }
};