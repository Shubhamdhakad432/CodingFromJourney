class Solution {
public:
    
    vector<vector<int>> diagonalSort(vector<vector<int>>& v) {
        int n=v.size(),m=v[0].size();
        
        vector<vector<int>>ans(n,vector<int>(m,0));
        
        for(int i=0;i<n;i++)
        {
            vector<int>x;
            int a=i,j=0;
            while(a<n && j<m)
            {
                x.push_back(v[a][j]);
                a++;
                j++;
            }
            sort(x.begin(),x.end());
            a=i;
            j=0;
            if(x.size()==0) continue;
            
            int k=0;
            while(a<n && j<m)
            {
                ans[a][j]=x[k++];
                a++;
                j++;
            }
        }
        
        for(int j=1;j<m;j++)
        {
            vector<int>x;
            int a=j,i=0;
            while(i<n && a<m)
            {
                x.push_back(v[i][a]);
                a++;
                i++;
            }
            sort(x.begin(),x.end());
            a=j;
            i=0;
            
            int k=0;
            while(i<n && a<m)
            {
                ans[i][a]=x[k++];
                a++;
                i++;
            }
        }
        
        return ans;
    }
};