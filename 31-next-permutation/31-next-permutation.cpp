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
        bool srt=true;
        int a=-1;
        int n=v.size();
        for(int i=n-2;i>=0;i--)
        {
            if(v[i]<v[i+1]) 
            {
                a=i;
                srt=false;
                break;
            }
        }
        
        if(srt)
        {
            reverse(v.begin(),v.end());
            return;
        }
        
        int b=-1;
        for(int i=n-1;i>=a;i--)
        {
            if(v[a]<v[i])
            {
                b=i;
                break;
            }
        }
        
        swap(v[a],v[b]);
        reverse(v.begin()+a+1,v.end());
    }
};