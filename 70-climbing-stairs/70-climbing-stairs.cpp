class Solution {
public:
    vector<int>dp;
    
    int bin(int n,int sum)
    {
        if(dp[sum]!=-1)
        {
            return dp[sum];    
        }
        
        if(sum==n)
        {
            dp[sum]=1;
            return 1;
        } 
        else if(sum>n) 
        {
            dp[sum]=0;
            return 0;
        }
        
        dp[sum] = bin(n,sum+1)+bin(n,sum+2);
        return dp[sum];
    }
    
    int climbStairs(int n) {
        dp.resize(50,-1);
        bin(n,0);
        return dp[0];
    }
};