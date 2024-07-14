class Solution {
public:
    string getEncryptedString(string s, int k) {
        string t = "";
        for(int i = 0; i < s.size(); i++){
            t += s[(i+k)%s.size()];
        }
        return t;
    }
};