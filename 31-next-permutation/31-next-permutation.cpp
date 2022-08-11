class Solution {
public:
    void rev(vector<int>&v,int a,int b)
    {
        while(a<=b)
        {
            swap(v[a],v[b]);
            a++;
            b--;
        }
    }
    
    void nextPermutation(vector<int>& v) {
        bool srt=false;
        int n=v.size();
        
        
        bool s = next_permutation(v.begin(),v.end());
        return;
        
        
        for(int i=1;i<n;i++)
        {
            if(v[i-1]>v[i]) srt=true;
        }
        if(srt)
        {
            reverse(v.begin(),v.end());
            return;
        }
        
        bool x=true;
        for(int i=n-1;i>0;i--)
        {
            for(int j=i-1;j>=0;j--)
            {
                if(v[i]>v[j])
                {
                    swap(v[i],v[j]);
                    x=false;
                    rev(v,j+1,n-1);
                    break;
                }
            }
            if(!x)
            {
                break;
            }
        }
    }
};