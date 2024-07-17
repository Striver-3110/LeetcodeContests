const auto _ = []{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();


class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        for(int i = 0; i < k-1; i++){
            colors.push_back(colors[i]);
        }
        int n = colors.size();
        int ans = 0;
        int len = 1;
        for(int i = 0; i + 1 < n; i++){
            if(colors[i] != colors[i+1])len++;
            else{
                if(len >= k){
                    ans += len - k + 1;
                }
                len = 1;
            }
        }
        if(len >= k){
            ans += len - k + 1;
        }
        return ans;
    }
};