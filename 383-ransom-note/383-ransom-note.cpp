class Solution {
public:
    bool canConstruct(string x, string y) {
        map<char,int>m;
        for(auto z:y) 
        {
            m[z]++;
        }
        
        for(auto z:x)
        {
            if(m[z]==0)
            {
                return false;
            }
            m[z]--;
            if(m[z]==0)
            {
                m.erase(z);
            }
        }
        return true;
    }
};