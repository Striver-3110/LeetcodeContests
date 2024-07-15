class Solution {
public:
    // Brute force
    // vector<string> validStrings(int n) {
        // vector<string> valid;
        // string s = "";
        // for(int i = 0; i < n; i++){
        //     s += '0';
        // }
        // valid.push_back(s);
        // for(int i = 1; i < pow(2,n); i++){
        //     int t = i;
        //     string temp = "";
        //     int cnt = n;
        //     while(t){
        //         int r = t%2;
        //         temp = to_string(r) + temp;
        //         cnt--;
        //         t/=2;
        //     }
        //     while(cnt--){
        //         temp = to_string(0) + temp;
        //     }
        //     valid.push_back(temp);

        // }
        // vector<string> ans;
        // for(int i = 0; i < pow(2,n); i++){
        //     bool flg = false;
        //     for(int j = 0; j < n-1; j++){
        //         if(valid[i][j] == '0' && valid[i][j+1] == '0'){
        //             flg = true;
        //             break;
        //         }
        //     }
        //     if(!flg)
        //         ans.push_back(valid[i]);
        // }
        // // cout<<"\n"<<valid.size()<<endl;
        // return ans;
    // }

    // Using backtracking
    // standard problem : generate all the binary strings of length n
    void backTrack(string&& str, int &n, vector<string>& valid){
        if(str.size() == n){
            valid.push_back(str);
            return;
        }
        str.push_back('1');
        backTrack(move(str),n,valid);
        str.pop_back();

        if(str[str.size()-1] == '0')return;
        
        str.push_back('0');
        backTrack(move(str),n,valid);
        str.pop_back();
        return;
    }
    vector<string> validStrings(int n) {
        vector<string> valid;
        backTrack("0",n,valid);
        backTrack("1",n,valid);
        return valid;
    }
};