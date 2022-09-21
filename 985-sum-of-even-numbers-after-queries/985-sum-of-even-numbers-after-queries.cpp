class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& v, vector<vector<int>>& q) {
        int n=q.size();
        int sum=0;
        
        int m=v.size();
        for(int i=0;i<m;i++)
        {
            if(v[i]&1) 
            {
                continue;
            }
            else
            {
                sum+=v[i];
            }
        }
        
        vector<int>ans(n,0);
        
        for(int i=0;i<n;i++)
        {
            if(v[q[i][1]]%2==0)
            {
                sum=sum-v[q[i][1]];
            }
            
            v[q[i][1]]+=q[i][0];
            if(v[q[i][1]]%2==0)
            {
                sum+=v[q[i][1]];
            }
            
            ans[i]=sum;
        }
        
        return ans;
    }
};