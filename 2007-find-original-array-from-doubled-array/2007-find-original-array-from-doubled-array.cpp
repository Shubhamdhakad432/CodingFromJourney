class Solution {
public:
    vector<int> findOriginalArray(vector<int>& v) {
        int n=v.size();
        if(n&1) 
        {
            return {};
        }
        
        multiset<int>s;
        vector<int>a;
        sort(v.begin(),v.end());
        
        for(int i=n-1;i>=0;i--)
        {
            if(s.count(v[i]*2))
            {
                a.push_back(v[i]);
                auto x=s.find(v[i]*2);
                s.erase(x);
            }
            else
            {
                s.insert(v[i]);
            }
        }
        
        if(a.size()!=(n/2))
        {
            return {};
        }
        
        return a;
    }
};