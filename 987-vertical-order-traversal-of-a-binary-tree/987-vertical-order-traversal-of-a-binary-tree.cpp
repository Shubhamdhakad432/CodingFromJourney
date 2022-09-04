class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* s) {
        vector<vector<int>>ans;
        map<int,map<int,multiset<int>>>m;
        pair<int,int>p={INT_MAX,INT_MIN};
        
        queue<pair<TreeNode*,pair<int,int>>>q;
        q.push({s,{0,0}});
        
        while(!q.empty())
        {
            int sz=q.size();
            while(sz--)
            {
                auto [x,a]=q.front();
                auto [y,z]=a;
                q.pop();
                
                if(x==NULL)
                {
                    continue;
                }
                
                m[y][z].insert(x->val);
                
                if(x->left!=NULL)
                {
                    q.push({x->left,{y-1,z+1}});
                }
                if(x->right!=NULL)
                {
                    q.push({x->right,{y+1,z+1}});
                }
            }
        }
        
        for(auto i:m)
        {
            vector<int>v;
            for(auto j:i.second)
            {
                for(auto k:j.second)
                {
                    v.push_back(k);
                }
            }
            ans.push_back(v);
        }
        return ans;
    }
};