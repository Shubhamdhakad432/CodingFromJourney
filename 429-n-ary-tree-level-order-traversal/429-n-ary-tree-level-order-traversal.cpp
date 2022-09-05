/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* s) {
        vector<vector<int>>v;
        if(s==NULL)
        {
            return v;
        }
        queue<Node*>q;
        q.push(s);
        v.push_back({s->val});
        vector<int>a;
        while(!q.empty())
        {
            int n=q.size();
            a.clear();
            for(int i=0;i<n;i++)
            {
                auto x = q.front();
                q.pop();
                for(auto z:x->children)
                {
                    a.push_back(z->val);
                    q.push(z);
                }
            }
            if(a.size()!=0)
                v.push_back(a);
        }
        return v;
    }
};