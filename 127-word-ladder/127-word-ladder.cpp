class Solution {
public:
    int ladderLength(string beg, string end, vector<string>& wl) {
        queue<string>q;
        q.push(beg);
        int dis=0,qs,n=beg.size();
        
        unordered_set<string>s(wl.begin(),wl.end());
        string z;
        if(s.count(end)==0) return 0;
        
        while(!q.empty())
        {
            qs=q.size();
            while(qs--)
            {
                auto x=q.front();
                q.pop();
                
                if(x==end)
                {
                    return dis+1;
                }
                
                for(int t=0;t<n;t++)
                {
                    z=x;
                    for(auto i='a';i<='z';i++)
                    {
                        z[t]=i;
                        if(s.count(z) && z!=x)
                        {
                            q.push(z);
                            s.erase(z);
                        }
                    }
                }
            }
            dis++;
        }
        return 0;
    }
};