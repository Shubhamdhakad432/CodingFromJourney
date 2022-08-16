class Solution {
public:    
    vector<int>dp;
    int n;
    int bin(vector<int>&v,int i,int sum)
    {
        if(i==n)
        {
            return sum;
        }
        else if(i>n)
        {
            return 1000;
        }
        
        if(dp[i]!=-1)
        {
            return dp[i];
        }
        
        dp[i]=v[i]+min(bin(v,i+1,sum),bin(v,i+2,sum));
        return dp[i];
    }
    
    int minCostClimbingStairs(vector<int>& v) 
    {
        n=v.size();
        dp.resize(n+1,-1);
        return min(bin(v,1,0),bin(v,0,0));  
    }
};