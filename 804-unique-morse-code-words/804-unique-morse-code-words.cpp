class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& v) {
        vector<string>code={".-",
                            "-...",
                            "-.-.",
                            "-..",
                            ".",
                            "..-.",
                            "--.",
                            "....",
                            "..",
                            ".---",
                            "-.-",
                            ".-..",
                            "--",
                            "-.",
                            "---",
                            ".--.",
                            "--.-",
                            ".-.",
                            "...",
                            "-",
                            "..-",
                            "...-",
                            ".--",
                            "-..-",
                            "-.--",
                            "--.."};
        
        set<string>s;
        for(auto x:v)
        {
            string z="";
            for(auto y:x)
            {
                z+=code[y-'a'];
            }
            s.insert(z);
        }
        return s.size();
    }
};