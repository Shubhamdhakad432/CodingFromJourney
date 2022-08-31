class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& v) {
        int n=v.size(),m=v[0].size();
        vector<vector<bool>>pac,atl,vis;
        pac.resize(n,vector<bool>(m,false));
        atl.resize(n,vector<bool>(m,false));
        vis.resize(n,vector<bool>(m,true));
        
        queue<pair<pair<int,int>,pair<int,int>>>q;
        for(int i=0;i<m;i++)
        {
            q.push({{0,i},{-1,-1}});
        }
        for(int i=1;i<n;i++)
        {
            q.push({{i,0},{-1,-1}});
        }
        
        while(!q.empty())
        {
            int k=q.size();
            for(int i=0;i<k;i++)
            {
                auto [x,y] = q.front();
                auto [a,b] = x;
                auto [c,d] = y;
                q.pop();
                
                if(a>=0 && a<n && b>=0 && b<m && vis[a][b])
                {
                    if(c!=-1 && d!=-1)
                    {
                        if(v[a][b]>=v[c][d])
                        {
                            pac[a][b]=true;
                            q.push({{a+1,b},{a,b}});
                            q.push({{a-1,b},{a,b}});
                            q.push({{a,b-1},{a,b}});
                            q.push({{a,b+1},{a,b}});
                            vis[a][b]=false;
                        }
                    }
                    else
                    {
                        pac[a][b]=true;
                        q.push({{a+1,b},{a,b}});
                        q.push({{a-1,b},{a,b}});
                        q.push({{a,b-1},{a,b}});
                        q.push({{a,b+1},{a,b}});
                        vis[a][b]=false;
                    }
                }
            }
        }
        
        vis.clear();
        vis.resize(n,vector<bool>(m,true));
        for(int i=0;i<m-1;i++)
        {
            q.push({{n-1,i},{-1,-1}});
        }
        for(int i=0;i<n;i++)
        {
            q.push({{i,m-1},{-1,-1}});
        }
        
        while(!q.empty())
        {
            int k=q.size();
            for(int i=0;i<k;i++)
            {
                auto [x,y] = q.front();
                auto [a,b] = x;
                auto [c,d] = y;
                q.pop();
                
                if(a>=0 && a<n && b>=0 && b<m && vis[a][b])
                {
                    if(c!=-1 && d!=-1)
                    {
                        if(v[a][b]>=v[c][d])
                        {
                            atl[a][b]=true;
                            q.push({{a+1,b},{a,b}});
                            q.push({{a-1,b},{a,b}});
                            q.push({{a,b-1},{a,b}});
                            q.push({{a,b+1},{a,b}});
                            vis[a][b]=false;
                        }
                    }
                    else
                    {
                        atl[a][b]=true;
                        q.push({{a+1,b},{a,b}});
                        q.push({{a-1,b},{a,b}});
                        q.push({{a,b-1},{a,b}});
                        q.push({{a,b+1},{a,b}});
                        vis[a][b]=false;
                    }
                }
            }
        }
        
        vector<vector<int>>ans;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(pac[i][j] && atl[i][j])
                {
                    ans.push_back({i,j});
                }
            }
        }
        return ans;
    }
};