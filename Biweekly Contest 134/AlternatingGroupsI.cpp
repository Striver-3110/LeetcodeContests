#include<vector>
#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    Solution(){
    }
    int numberOfAlternatingGroups(vector<int>& colors) {
        // as k = 3
        // we need to check only 2 values after the n-1th element
        int i = 0; 
        // here we will be simply checking for the ith element
        // to group be size of k = 3
        // i,i+1, i+2
        // where the relation of each of them should be
        // colors[i] != colors[i+1] && colors[i] == colors[i+2]
        // for for overflow and as the colors is circular in nature
        // colors[i] != colors[(i+1)%n] && colors[i] == colors[(i+2)%n]
        int ans = 0;
        int n = colors.size();
        for(int i = 0;i < n; i++){
            if(colors[i] != colors[(i+1)%n] && colors[i] == colors[(i+2)%n]) ans++;
        }
        return ans;

        // int k = 3;
        // for(int i = 0; i < k-1; i++){
        //     colors.push_back(colors[i]);
        // }
        // int n = colors.size();
        // int ans = 0;
        // int len = 1;
        // for(int i = 0; i + 1 < n; i++){
        //     if(colors[i] != colors[i+1])len++;
        //     else{
        //         if(len >= k){
        //             ans += len - k + 1;
        //         }
        //         len = 1;
        //     }
        // }
        // if(len >= k){
        //     ans += len - k + 1;
        // }
        // return ans;
    }
};

int main(){
    Solution s;
    vector<int> vec = {0,1,0,1};
    cout<< s.numberOfAlternatingGroups(vec);

}