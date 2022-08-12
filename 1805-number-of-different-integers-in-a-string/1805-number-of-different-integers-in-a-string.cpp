class Solution {
public:
    int numDifferentIntegers(string s) {
        unordered_set<string>st;
        string x;
        for(int i=0;i<s.size();i++)
        {
            x="";
            if('0'<=s[i] && s[i]<='9')
            {
                while(s[i]=='0') i++;
                while('0'<=s[i] && s[i]<='9')
                {
                    x.push_back(s[i]);
                    i++;
                }
                i--;
                st.insert(x);
            }
        }
        if(x!="") st.insert(x);
        return st.size();
    }
};