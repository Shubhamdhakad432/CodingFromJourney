class Solution {
public:
    string smallestNumber(string pattern) {
        stack<int>s;
        string ans = "";
        if(pattern[0] == 'I') ans += '1';
        else s.push('1');
        for(int i = 1; i <= pattern.size(); i++){
            if(pattern[i-1] == 'I'){
                while(!s.empty()){  ans += s.top(); s.pop(); }
            }
            s.push('0' + i+1);
        }
        while(!s.empty()){ ans += s.top(); s.pop();  }
        return ans;
    }
};