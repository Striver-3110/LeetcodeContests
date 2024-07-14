class Solution {
public:
    long long minimumCost(int m, int n, vector<int>& hc, vector<int>& vc) {
        sort(hc.begin(),hc.end());
        sort(vc.begin(),vc.end());

        long long tc = 0;
        int i = m-2; 
        int j = n-2;
        int hCuts = 1;
        int vCuts = 1;
        while(i >= 0 && j >= 0){
            if(hc[i] > vc[j]){
                tc += hc[i] * vCuts;
                i--;
                hCuts++;
            }else{
                tc += vc[j] * hCuts;
                j--;
                vCuts++;
            }
        }
        while(i >= 0){
            tc += hc[i] * vCuts;
            i--;
        }
        while(j >= 0){
            tc += vc[j] * hCuts;
            j--;
        }
        return tc;
    }
};