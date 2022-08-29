class Solution {
public:
    void bin(vector<vector<char>> &v,int i,int j)
    {
        if(i>=0 && j>=0 && i<v.size() && j<v[0].size())
        {
            if(v[i][j]=='1')
            {
                v[i][j]='0';
                bin(v,i+1,j);
                bin(v,i-1,j);
                bin(v,i,j-1);
                bin(v,i,j+1);
            }
        }
    }
    
    int numIslands(vector<vector<char>>& v) {
        int n=v.size(),m=v[0].size();
        int cnt=0;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(v[i][j]=='1')
                {
                    cnt++;
                    bin(v,i,j);
                }
            }
        }
        return cnt;
    }
};