class Solution {
public:
    int firstMissingPositive(vector<int>& v) {
        set<int>s;
        for(auto x:v) 
        {
            if(x>0) s.insert(x);
        }
        if(s.size()==0) return 1;
        
        int a=1;
        for(auto x:s)
        {
            if(x==a)
            {
                a++;
            }
            else
            {
                return a;
            }
        }
        return a;
    }
};